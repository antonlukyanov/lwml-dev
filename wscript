#!/usr/bin/env python3

from scripts.waf.cxx_lwml import DebugContext

top = '.'
out = '__build'

def options(opt):
    opt.load('compiler_cxx')

def configure(conf):
    conf.load('compiler_cxx')
    conf.load('cxx_autodeps cxx_lwml', tooldir='scripts/waf')

def build(bld):
    bld.recurse([
        'lwml',
    ])
