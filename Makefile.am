# Install the pkg-config file.
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = src/libabsdev.pc src/libivariance.pc src/libmean.pc src/libpstat.pc src/libpstat_mulvar.pc src/libpstat_ngram.pc src/libpstat_off.pc src/libstat.pc src/libstat_off.pc src/libstat_off_diff.pc src/libsum.pc src/libvariance.pc src/libzepast.pc src/absdev_test.pc src/ivariance_test.pc src/mean_test.pc src/stat_off_diff_test.pc src/sum_test.pc src/variance_test.pc src/zepast_test.pc

DISTCLEANFILES = $(pkgconfig_DATA)
EXTRA_DIST = src/libabsdev.pc.in src/libivariance.pc.in src/libmean.pc.in src/libpstat.pc.in src/libpstat_mulvar.pc.in src/libpstat_ngram.pc.in src/libpstat_off.pc.in src/libstat.pc.in src/libstat_off.pc.in src/libstat_off_diff.pc.in src/libsum.pc.in src/libvariance.pc.in src/libzepast.pc.in src/absdev_test.pc.in src/ivariance_test.pc.in src/mean_test.pc.in src/stat_off_diff_test.pc.in src/sum_test.pc.in src/variance_test.pc.in src/zepast_test.pc.in

SUBDIRS = src
dist_doc_DATA = README.md
ACLOCAL_AMFLAGS = -I m4

