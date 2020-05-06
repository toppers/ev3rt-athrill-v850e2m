APPL_ASMOBJS :=
ifdef USE_CXX
	APPL_CXXOBJS += app.o
	APPL_COBJS +=
else
	APPL_COBJS += app.o
endif
