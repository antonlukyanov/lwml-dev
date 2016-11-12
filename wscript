#!/usr/bin/env python3

# This enables default 'debug' command which duplicates 'build'
# command but represents different `variant` and adds debug flags.
# You can run 'waf debug -v --targets=mcontr' to see the process of build.
import scripts.waf.cxx_lwml


top = '.'
out = '__build'
tooldir = 'scripts/waf'


def options(opt):
    opt.load('cxx_lwml', tooldir=tooldir)


def configure(conf):
    conf.load('cxx_lwml', tooldir=tooldir)


def build(bld):
    bld.recurse('lwml', optional=True)
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
