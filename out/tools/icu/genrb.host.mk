# This file is generated by gyp; do not edit.

TOOLSET := host
TARGET := genrb
DEFS_Debug := \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DV8_IMMINENT_DEPRECATION_WARNINGS' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DUCONFIG_NO_SERVICE=1' \
	'-DU_ENABLE_DYLOAD=0' \
	'-DU_STATIC_IMPLEMENTATION=1' \
	'-DU_HAVE_STD_STRING=1' \
	'-DUCONFIG_NO_BREAK_ITERATION=0' \
	'-DDEBUG' \
	'-D_DEBUG' \
	'-DV8_ENABLE_CHECKS'

# Flags passed to all source files.
CFLAGS_Debug := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++1y

INCS_Debug := \
	-I$(srcdir)/deps/icu-small/source/common \
	-I$(srcdir)/deps/icu-small/source/i18n \
	-I$(srcdir)/deps/icu-small/source/tools/toolutil

DEFS_Release := \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DV8_IMMINENT_DEPRECATION_WARNINGS' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DUCONFIG_NO_SERVICE=1' \
	'-DU_ENABLE_DYLOAD=0' \
	'-DU_STATIC_IMPLEMENTATION=1' \
	'-DU_HAVE_STD_STRING=1' \
	'-DUCONFIG_NO_BREAK_ITERATION=0'

# Flags passed to all source files.
CFLAGS_Release := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++1y

INCS_Release := \
	-I$(srcdir)/deps/icu-small/source/common \
	-I$(srcdir)/deps/icu-small/source/i18n \
	-I$(srcdir)/deps/icu-small/source/tools/toolutil

OBJS := \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/genrb.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/ustr.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/wrtxml.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/rle.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/parse.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/prscmnts.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/rbutil.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/read.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/errmsg.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/filterrb.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/reslist.o \
	$(obj).host/$(TARGET)/deps/icu-small/source/tools/genrb/wrtjava.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# Make sure our dependencies are built before any of us.
$(OBJS): | $(obj).host/tools/icu/libicutools.a $(obj).host/tools/icu/icu_implementation.stamp $(obj).host/tools/icu/icu_uconfig.stamp

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic

LDFLAGS_Release := \
	-pthread \
	-rdynamic

LIBS :=

$(builddir)/genrb: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(builddir)/genrb: LIBS := $(LIBS)
$(builddir)/genrb: LD_INPUTS := $(OBJS) $(obj).host/tools/icu/libicutools.a
$(builddir)/genrb: TOOLSET := $(TOOLSET)
$(builddir)/genrb: $(OBJS) $(obj).host/tools/icu/libicutools.a FORCE_DO_CMD
	$(call do_cmd,link)

all_deps += $(builddir)/genrb
# Add target alias
.PHONY: genrb
genrb: $(builddir)/genrb

