CC = g++
CPPFLAGS = -MMD -MP -Os -DOBJC_OLD_DISPATCH_PROTOTYPES -g -std=c++20 -stdlib=libc++ -I.
IGNORED_WARNINGS = -w
INC_DIRS = -I.
BUILD_DIR = build
OBJS = $(addprefix $(BUILD_DIR)/, FEHLCD.o FEHRandom.o FEHSD.o tigr.o FEHUtility.o FEHImages.o)

ifeq ($(OS),Windows_NT)
	LDFLAGS = -lopengl32 -lgdi32
	EXEC = game.exe
else
	UNAME := $(shell uname)
	ifeq ($(UNAME),Darwin)
		LDFLAGS = -framework OpenGL -framework Cocoa
	else
		LDFLAGS = `pkg-config --libs --cflags opengl x11 glx`
	endif
	EXEC = game
endif

recursiveWildcard=$(foreach d,$(wildcard $(1:=/*)),$(call recursiveWildcard,$d,$2) $(filter $(subst *,%,$2),$d))

STUDENT_CPP_FILES := $(filter-out src/lib/%, $(call recursiveWildcard, src, *.cpp))
STUDENT_H_FILES := $(filter-out src/lib/%, $(call recursiveWildcard, src, *.h))
STUDENT_COMPILED_OBJECT_FILES := $(addprefix $(BUILD_DIR)/, $(notdir $(patsubst %.cpp, %.o, $(STUDENT_CPP_FILES))))

all: $(BUILD_DIR) libraries studentFiles
	$(CC) $(CPPFLAGS) $(OBJS) $(STUDENT_COMPILED_OBJECT_FILES) -o $(EXEC) $(LDFLAGS) $(IGNORED_WARNINGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: src/lib/%.cpp
	$(CC) $(IGNORED_WARNINGS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/%.o: src/lib/%.c
	$(CC) $(IGNORED_WARNINGS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(IGNORED_WARNINGS) $(INC_DIRS) -c $< -o $@

studentFiles: $(STUDENT_CPP_FILES)
	@for file in $(STUDENT_CPP_FILES); do \
		obj=$(BUILD_DIR)/$$(basename $$file .cpp).o; \
		$(CC) $(CPPFLAGS) $(IGNORED_WARNINGS) $(INC_DIRS) -c $$file -o $$obj; \
	done

libraries: $(OBJS)

clean:
	@rm -rf $(BUILD_DIR) $(EXEC)
