# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := uvwasi
DEFS_Debug := \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DV8_IMMINENT_DEPRECATION_WARNINGS' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-D_GNU_SOURCE' \
	'-D_POSIX_C_SOURCE=200112' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DDEBUG' \
	'-D_DEBUG' \
	'-DV8_ENABLE_CHECKS'

# Flags passed to all source files.
CFLAGS_Debug := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-fvisibility=hidden \
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
	-I$(srcdir)/deps/uvwasi/include \
	-I$(srcdir)/deps/uv/include

DEFS_Release := \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DV8_IMMINENT_DEPRECATION_WARNINGS' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-D_GNU_SOURCE' \
	'-D_POSIX_C_SOURCE=200112' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64'

# Flags passed to all source files.
CFLAGS_Release := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-fvisibility=hidden \
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
	-I$(srcdir)/deps/uvwasi/include \
	-I$(srcdir)/deps/uv/include

OBJS := \
	$(obj).target/$(TARGET)/deps/uvwasi/src/clocks.o \
	$(obj).target/$(TARGET)/deps/uvwasi/src/fd_table.o \
	$(obj).target/$(TARGET)/deps/uvwasi/src/path_resolver.o \
	$(obj).target/$(TARGET)/deps/uvwasi/src/poll_oneoff.o \
	$(obj).target/$(TARGET)/deps/uvwasi/src/uv_mapping.o \
	$(obj).target/$(TARGET)/deps/uvwasi/src/uvwasi.o \
	$(obj).target/$(TARGET)/deps/uvwasi/src/wasi_rights.o \
	$(obj).target/$(TARGET)/deps/uvwasi/src/wasi_serdes.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

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

$(obj).target/deps/uvwasi/libuvwasi.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/deps/uvwasi/libuvwasi.a: LIBS := $(LIBS)
$(obj).target/deps/uvwasi/libuvwasi.a: TOOLSET := $(TOOLSET)
$(obj).target/deps/uvwasi/libuvwasi.a: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,alink_thin)

all_deps += $(obj).target/deps/uvwasi/libuvwasi.a
# Add target alias
.PHONY: uvwasi
uvwasi: $(obj).target/deps/uvwasi/libuvwasi.a

# Add target alias to "all" target.
.PHONY: all
all: uvwasi

