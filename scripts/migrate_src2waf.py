#!/usr/bin/env python3

import os
import re
import argparse


parser = argparse.ArgumentParser(
    description="""This script recursively processes source files in specified folder and replaces
                   includes of the form #include "header.h" with #inlcude "abspath/header.h". It
                   also converts text encoding from windows-1251 to utf-8."""
)
parser.add_argument('path')
parser.add_argument(
    '-p', '--prefix',
    help='''Prefix for includes, i.e. #include "<prefix>/abspath/header.h". By default prefix is
            the last component of <path> argument.''',
    action='store'
)
parser.add_argument(
    '-e', '--exclude',
    help='Comma-separated list of directories in <path> which will be excluded from processing.',
    action='store'
)

args = parser.parse_args()

if not args.prefix:
    prefix = args.path.split('/')[-1]
else:
    prefix = args.prefix.strip('/')

if args.exclude:
    exclude = args.exclude.split(',')
else:
    exclude = []

paths = []
path = args.path
includes = {}

while path:
    if path:
        for entry in os.scandir(path):
            fname = entry.name
            if not fname.startswith('.'):
                if entry.is_file() and fname.endswith(('.cc', '.h')):
                    include = os.path.join(
                        prefix,
                        entry.path.replace(args.path.strip('/') + '/', ''),
                    )
                    includes[fname] = (include, entry.path)
                elif entry.is_dir():
                    if path == args.path and entry.name not in exclude or path != args.path:
                        paths.append(entry.path)
    try:
        path = paths.pop()
    except IndexError:
        path = False

for _, (_, fpath) in includes.items():
    print('>> Processing %s' % fpath)

    try:
        file = open(fpath, 'r', encoding='utf-8')
        lines = file.readlines()
    except UnicodeDecodeError:
        file.close()
        file = open(fpath, 'r', encoding='windows-1251')
        lines = file.readlines()

    for i, line in enumerate(lines):
        line = line.strip()
        m = re.match('^\s*#include "([^/]+\.h)".*$', line)
        if m and m.group(1) in includes:
            oldinclude = m.group(1)
            newinclude = includes[oldinclude][0]
            newline = lines[i].replace(oldinclude, newinclude)
            lines[i] = lines[i].replace(oldinclude, newinclude)
            print('    replacing  %s --->' % oldinclude)
            print('               %s' % newinclude)
    print()
    file.close()

    with open(fpath, 'w', encoding='utf-8') as file:
        file.writelines(lines)
