#!/usr/bin/env python3

"""
This script recursively processes source files in specified folder and replaces includes of the
form #include "header.h" with #inlcude "abspath/header.h". It also converts text encoding from
windows-1251 to utf-8.
"""

import os
import re
import argparse


parser = argparse.ArgumentParser(
    description=""
)
parser.add_argument('path')
args = parser.parse_args()

includes = {}
prefix = args.path.split('/')[-1]
paths = []
path = args.path

while path:
    if path:
        for entry in os.scandir(path):
            fname = entry.name
            if not fname.startswith('.') and entry.is_file() and fname.endswith(('.cc', '.h')):
                include = os.path.join(
                    prefix,
                    entry.path.replace(args.path.strip('/') + '/', ''),
                )
                includes[fname] = (include, entry.path)
            elif entry.is_dir():
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
