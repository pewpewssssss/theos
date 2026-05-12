TARGET := iphone:clang:16.5:12.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

TOOL_NAME = debload
debload_FILES = main.mm
debload_CFLAGS = -fobjc-arc
# This ensures it's signed correctly for iOS 12+
debload_CODESIGN_FLAGS = -S

include $(THEOS_MAKE_PATH)/tool.mk
