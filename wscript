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
    # Default definitions for project which contains lwml library.
    conf.load('cxx_lwml', tooldir='scripts/waf')


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
