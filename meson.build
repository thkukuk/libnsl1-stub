project(
  'libnsl',
  'c',
  meson_version : '>= 0.58.0',
  default_options : ['buildtype=debugoptimized',
  		  'default_library=shared',
                  'c_std=gnu11',
                  'prefix=/usr',
		  'b_pie=true',
		  'warning_level=0',],
  license : 'LGPLv2+',
  version : '1.0.0',
)

cc = meson.get_compiler('c')
pkg = import('pkgconfig')
inc = include_directories('include')

libnsl_src = files(
  'src/ypclnt.c',
  'src/xdr.c'
)

mapfile = 'src/libnsl-'+host_machine.cpu_family()+'.map'
version_flag = '-Wl,--version-script,@0@/@1@'.format(meson.current_source_dir(), mapfile)

lib = library(
  'nsl',
  libnsl_src,
  include_directories : inc,
  install : true,
  link_args : version_flag,
  link_depends : mapfile,
  version : meson.project_version(),
  soversion : '1',
)

# Unit tests
#subdir('tests')
