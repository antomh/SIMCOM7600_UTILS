# Before compilation you should run "sim-crosscompile-env-init" script from sdk sources. Like that:
# source *path_to_script*/sim-crosscompile-env-init
# make all
# Then bin file appears in ./bin folder.

CFLAGS = -c -O2 

MAIN_DIR = .

BIN_NAME = sdk-version

TARGET_BIN_DIR = $(MAIN_DIR)/bin
TARGET_OBJ_DIR = $(MAIN_DIR)/obj

INCLUDE_PREFIX = -I

LINK_PREFIX = -L

ALL_PATHS = $(TARGET_OBJ_DIR)
ALL_PATHS += ./inc
ALL_PATHS += ./sdk-includes/common
ALL_PATHS += ./sdk-includes/curl
ALL_PATHS += ./sdk-includes/data
ALL_PATHS += ./sdk-includes/dsi
ALL_PATHS += ./sdk-includes/dsutils
ALL_PATHS += ./sdk-includes/gps
ALL_PATHS += ./sdk-includes/json-c
ALL_PATHS += ./sdk-includes/linux
ALL_PATHS += ./sdk-includes/mqtt
ALL_PATHS += ./sdk-includes/openssl
ALL_PATHS += $(LIB_PATH)/usr/include/qmi
ALL_PATHS += $(LIB_PATH)/usr/include/qmi-framework

ALL_INCLUDES = $(addprefix $(INCLUDE_PREFIX), $(ALL_PATHS))

ALL_LINKS += $(addprefix $(LINK_PREFIX), ./libs)

STD_LIB = $(LIB_PATH)/usr/lib/libdsi_netctrl.so   \
          $(LIB_PATH)/usr/lib/libdsutils.so       \
          $(LIB_PATH)/usr/lib/libqmiservices.so   \
          $(LIB_PATH)/usr/lib/libqmi_cci.so       \
          $(LIB_PATH)/usr/lib/libqmi_common_so.so \
          $(LIB_PATH)/usr/lib/libqmi.so           \
	 	  $(LIB_PATH)/lib/libpthread.so.0	      \
	 	  $(LIB_PATH)/usr/lib/libqdi.so		      \
	 	  $(LIB_PATH)/usr/lib/librt.so		      \
	 	  $(LIB_PATH)/lib/libcrypto.so		      \
	 	  $(LIB_PATH)/usr/lib/libdl.so		      \
          $(LIB_PATH)/usr/lib/libloc_api_v02.so   \
          $(LIB_PATH)/usr/lib/libloc_xtra.so      \
          $(LIB_PATH)/usr/lib/libloc_pla.so       \
          $(LIB_PATH)/usr/lib/libloc_hal_test_shim_extended.so

BIN_OBJS = $(TARGET_OBJ_DIR)/main.o


all: clear prep app

clear:
	@rm -rf $(TARGET_OBJ_DIR) $(TARGET_BIN_DIR)

prep:
	@if [ ! -d $(TARGET_BIN_DIR) ]; then mkdir $(TARGET_BIN_DIR); fi
	@if [ ! -d $(TARGET_OBJ_DIR) ]; then mkdir $(TARGET_OBJ_DIR); fi

$(TARGET_OBJ_DIR)/%.o: $(MAIN_DIR)/%.c
	@echo ---------------------------------------------------------
	@echo "BUILD OBJECT:" $(@)
	@echo "SOURCE: " $<
	@$(CC) $(CFLAGS) $(ALL_INCLUDES) -o $@ $<
	@echo ---------------------------------------------------------

app: $(BIN_OBJS)
	@echo "Create project BIN.\n"
	@echo "COMPILER: " $(CC) "\n"
	@echo "LINKS: " $(ALL_LINKS) "\n"
	@echo "LIBRARIES: " $(STD_LIB) "\n"
	@echo "OUTPUT FILE NAME: " $(TARGET_BIN_DIR)/$(BIN_NAME)
	@$(CC) \
		$(ALL_LINKS) \
		$(STD_LIB) \
		-o $(TARGET_BIN_DIR)/$(BIN_NAME) \
		$^ -lsdk