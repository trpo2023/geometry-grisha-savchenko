APP_NAME = geometry
LIB_NAME = LibGeometry

source_dirs = thirdparty src/geometry src/LibGeometry 

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = $(addprefix -I,$(source_dirs)) -MD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

SRC_EXT = cpp
CC = g++

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

.PHONY: all
all: $(APP_PATH)

-include $(wildcard *.d) 

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
	$(RM) $(test_obj)
	$(RM) $(test_exe)
	

Test_Name = test
Test_Path = obj/src/test1
test_exe = bin/testm

.PHONY: test

test:$(test_exe)

$(test_exe):$(Test_Path)/main.o obj/src/test1/$(Test_Name).o $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@
	
$(Test_Path)/$(Test_Name).o: test1/$(Test_Name).cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(Test_Path)/main.o: test1/main.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
	

