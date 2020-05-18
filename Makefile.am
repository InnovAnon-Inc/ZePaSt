# Install the pkg-config file.
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = src/libabsdev.pc src/libivariance.pc src/libmean.pc src/libpstat.pc src/libpstat_mulvar.pc src/libpstat_ngram.pc src/libpstat_off.pc src/libstat.pc src/libstat_off.pc src/libstat_off_diff.pc src/libsum.pc src/libvariance.pc src/libzepast.pc

DISTCLEANFILES = $(pkgconfig_DATA)
EXTRA_DIST = src/libabsdev.pc.in src/libivariance.pc.in src/libmean.pc.in src/libpstat.pc.in src/libpstat_mulvar.pc.in src/libpstat_ngram.pc.in src/libpstat_off.pc.in src/libstat.pc.in src/libstat_off.pc.in src/libstat_off_diff.pc.in src/libsum.pc.in src/libvariance.pc.in src/libzepast.pc.in

SUBDIRS = src
dist_doc_DATA = README.md
ACLOCAL_AMFLAGS = -I m4

