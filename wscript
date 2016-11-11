#!/usr/bin/env python3

# This enables default 'debug' command which duplicates 'build'
# command but represents different `variant build` and adds debug flags.
# You can run 'waf debug -v --targets=mcontr' to see the process of build.
import scripts.waf.cxx_lwml

top = '.'
out = '__build'


def options(opt):
    opt.load('cxx_lwml', tooldir='scripts/waf')


def configure(conf):
    conf.load([
        # Automatic dependency search. This also add 'autodeps' logging zone.
        # You can see the output by providing flag '--zones=autodeps'.
        'cxx_autodeps',
        # Default definitions for project which contains lwml library.
        'cxx_lwml'
    ], tooldir='scripts/waf')


def build(bld):
    bld.recurse('lwml', opt=True)
    bld.recurse([
        'tests-manual/mcontr',
        'tests-manual/resamp',
        'tests',
        'demo/fft2d_timing',
        'demo/float-demo',
        'demo/lltimer',
        'demo/round-demo',
        'demo/sqsum',
    ])
