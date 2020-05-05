#
# Makefile for a workspace of EV3 Platform(ASP3).
#

#
# Include configurations of EV3RT(ASP3) SDK
#
SDKDIR = ..
WSPDIR = $(basename $(PWD))
ASPMAKEFILE = Makefile.asp

include $(SDKDIR)/Makefile.sdk.conf

.PHONY: all
all: 
	@mkdir -p  $(WSPDIR)/$(app)/deps
	@make --file $(ASPMAKEFILE) -C $(app) all
clean:
	@make --file $(ASPMAKEFILE) -C $(app) clean

.PHONY: clean

