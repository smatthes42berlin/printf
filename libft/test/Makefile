# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 12:02:07 by smatthes          #+#    #+#              #
#    Updated: 2023/05/29 16:00:53 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLEANUP = rm -f
MKDIR = mkdir -p
TARGET_EXTENSION=out


.PHONY: clean
.PHONY: test

PATHROOT = ../
PATHU = $(PATHROOT)unity/src/
PATHS = $(PATHROOT)src/
PATHT = $(PATHROOT)test/
PATHB = $(PATHROOT)build/
PATHD = $(PATHROOT)build/depends/
PATHO = $(PATHROOT)build/objs/
PATHR = $(PATHROOT)build/results/

BUILD_PATHS = $(PATHB) $(PATHD) $(PATHO) $(PATHR)

SRCT = $(wildcard $(PATHT)*.c)
# SRCT = $(PATHT)ft_split_str.c

COMPILE=cc -c
LINK=cc
# -MM tells gcc to output header dependencies for the compile file(s), but only 
# those that are in single quotes (it will exclude system headers).
# -MG tells gcc that it's okay if it runs into headers that it can't find. 
# This is going to be all of the headers, honestly, because we also (purposefully) 
# haven't told gcc anything about our include paths. We're looking for very shallow 
# dependency tracking: just the files that are included in the test file.
# -MF tells gcc we want the header dependencies to be written to a file. The next 
# argument should be the name of the file to write to, which is why we have placed 
# the dependency file first in our rule above.
DEPEND=cc -MM -MG -MF
CFLAGS= -Wall -Wextra -Werror -I. -I$(PATHU) -I$(PATHS) -DTEST

# $(patsubst pattern,replacement,text)
# % matches any number of characters, match-string is transported to results
# creates one file TestSomething.txt for each file TestSomething.c in SRCT
RESULTS = $(patsubst $(PATHT)test_%.c,$(PATHR)test_%.txt,$(SRCT) )

PASSED = `grep -s PASS $(PATHR)*.txt`
FAIL = `grep -s FAIL $(PATHR)*.txt`
IGNORE = `grep -s IGNORE $(PATHR)*.txt`


# grab and display results from results files
test: $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

# running test executables and piping output to results files
# ./$< => run executable
# > $@ => pipe the output data to result file (name of this rule)
# 2>&1 => combine stdout and stderr over stdout
$(PATHR)%.txt: $(PATHB)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

# build executable from object files
# $^ => all the dependencies
$(PATHB)test_%.$(TARGET_EXTENSION): $(PATHO)test_%.o $(PATHO)%.o $(PATHO)unity.o #$(PATHD)test_%.d
	$(LINK) -o $@ $^

# build object files from source c files
# :: means rule is terminating, if make can't find any of the file associated, it raises a problem
# testfiles
$(PATHO)%.o:: $(PATHT)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

# sourcefiles
$(PATHO)%.o:: $(PATHS)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

# unityfiles
$(PATHO)%.o:: $(PATHU)%.c $(PATHU)%.h
	$(COMPILE) $(CFLAGS) $< -o $@

# dependencies
# see above
$(PATHD)%.d:: $(PATHT)%.c
	$(DEPEND) $@ $<

# create build directories
$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHD):
	$(MKDIR) $(PATHD)

$(PATHO):
	$(MKDIR) $(PATHO)

$(PATHR):
	$(MKDIR) $(PATHR)

clean:
	$(CLEANUP) $(PATHO)*.o
	$(CLEANUP) $(PATHB)*.$(TARGET_EXTENSION)
	$(CLEANUP) $(PATHR)*.txt

# tell make, that intermediate files are important to us
# otherwise make will delete these when its finished
# and it has to start over the entire process everytime we call it
.PRECIOUS: $(PATHB)test_%.$(TARGET_EXTENSION)
# .PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt