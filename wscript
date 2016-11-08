#!/usr/bin/env python3

# This enables default 'debug' command which duplicates 'build'
# command but represents different `variant build` and adds debug flags.
# You can run 'waf debug -v --targets=mcontr' to see the process of build.
from scripts.waf.cxx_lwml import DebugContext


top = '.'
out = '__build'


def options(opt):
    # Loading command line options like --check-cxx-compiler.
    opt.load('compiler_cxx')


def configure(conf):
    # Loading compiler configuration capabilities and build commands.
    conf.load('compiler_cxx')
    conf.load([
        # Automatic dependency search. This also add 'autodeps' logging zone.
        # You can see the output by providing flag '--zones=autodeps'.
        'cxx_autodeps',
        # Default definitions for project which contains lwml library.
        'cxx_lwml'
    ], tooldir='scripts/waf')


def build(bld):
    bld.recurse([
        'lwml',
        'tests-manual/mcontr',
        'tests-manual/resamp',
    ])
