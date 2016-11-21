#!/usr/bin/env python3

import os
# This enables default 'debug' command which duplicates 'build'
# command but represents different `variant` and adds debug flags.
# You can run 'waf debug -v --targets=mcontr' to see the process of build.
import scripts.waf.cxx_lwml


top = '.'
out = '__build'
tooldir = 'scripts/waf'


def options(opt):
    default_destdir = os.environ.get('DEVENV_HOME', '/usr/local')

    gr = opt.get_option_group('install/uninstall options')
    gr.add_option(
        '--destdir',
        help='installation root [default: %r]' % default_destdir,
        default=default_destdir,
        dest='destdir'
    )

    gr = opt.get_option_group('build and install options')

    gr.add_option(
        '--lwml',
        help='build/install only lwml',
        action='store_true',
        default=False,
        dest='lwml'
    )

    opt.load('cxx_lwml', tooldir=tooldir)
    opt.recurse('lwml')


def configure(conf):
    conf.load('cxx_lwml', tooldir=tooldir)
    # Automatic dependency search. This also add 'autodeps' logging zone.
    # You can see the output by providing flag '--zones=autodeps'.
    conf.load('cxx_autodeps', tooldir=tooldir)
    conf.recurse('lwml')
    conf.env.DESTDIR = conf.options.destdir


def build(bld):
    if not bld.options.lwml:
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
    else:
        bld.recurse('lwml')
