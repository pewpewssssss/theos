# Target iOS 12.5 for your iPad Mini 2
TARGET := iphone:clang:12.5:12.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

TOOL_NAME = debload

# 1. Point to your Swift file
debload_FILES = main.swift

# 2. Tell Theos you are using Swift
debload_SWIFTFLAGS = -sdk $(THEOS)/sdks/iPhoneOS12.5.sdk
# Optional: Add libraries if needed
debload_FRAMEWORKS = Foundation

include $(THEOS_MAKE_PATH)/tool.mk
