

OUTPUT_FORMAT("elf32-v850-rh850","elf32-v850-rh850","elf32-v850-rh850")
OUTPUT_ARCH(v850-rh850)


MEMORY
{
	INTROM(raxi) :  org = 0x00000000, len = 2048k
	INTDATA(raxi) : org = 0x00200000, len = 2048k
	INTRAM(wax)  : org = 0x05FF7000, len = 10240k
	INTRAM2(wax)  : org = 0x07FF7000, len = 10240k
};

PROVIDE(__stack = 0);
PROVIDE(software_init_hook = 0);
PROVIDE(_software_term_hook = 0);
PROVIDE(hardware_init_hook = 0);
PROVIDE(hardware_term_hook = 0);

SECTIONS
{
	.vector : AT(0)
	{
		*(.vectors)
	} > INTROM

	.text :
	{
		__text = . ;
		*(.text)
		_etext = . ;
	} > INTROM

	.call_table_data ALIGN (4) :
	{
	PROVIDE(__ctbp = .);
	*(.call_table_data)
	} > INTROM

	.call_table_text :
	{
	*(.call_table_text)
	} > INTROM

	. = ALIGN(4);
	.rodata : {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata.*)
        *(.data.rel.ro)
        . = ALIGN(4);
        ___init_array_start = .;
	*(.ctors)
        *(SORT(.init_array.*))
        *(.init_array)
        ___init_array_end = .;
        __fini_array_start = .;
        *(SORT(.fini_array.*))
        *(.fini_array)
        __fini_array_end = .;
	 } > INTROM

	_textend = .;

	. = ALIGN(4);

	__idata_start = . ;

	.data	:  AT(__idata_start)
	{
		. = ALIGN(4);
		__data_start = . ;
        	*(.rosdata)
		*(.sdata)
		PROVIDE (__gp = .);
		*(.data)
		. = ALIGN(4);
		_edata	=  . ;
	} > INTDATA

	__idata_end = __idata_start + SIZEOF(.data);
	. = ALIGN(4);
	__srdata_start = . ;
	.sdata	:  AT(__srdata_start)
	{
		. = ALIGN(4);
		__sdata_start = . ;
		. = ALIGN(4);
		_esdata	=  . ;
	} > INTDATA

	__srdata_end = __srdata_start + SIZEOF(.sdata);



	__srdata_start = 0x00200000 ;
	.sdata	:  AT(__srdata_start)
	{
		. = ALIGN(4);
		__sdata_start = . ;
		PROVIDE (__gp = . + 0x8000);
		*(.sdata)
		. = ALIGN(4);
		_esdata	=  . ;
	} > INTRAM

	__srdata_end = __srdata_start + SIZEOF(.sdata);


	.bss	   :
	{
	  . = ALIGN(4);
	  __bss_start = .;
	  *(.bss)
	  *(COMMON)
	  . = ALIGN(4);
	  __bss_end = .;
	} > INTRAM

	.bss_noclr	   :
	{
	  . = ALIGN(4);
	  *(.appheap)
	  *(COMMON)
	  . = ALIGN(4);
	} > INTRAM2


	.tdata ALIGN (4) :
	{
		PROVIDE (__ep = .);
		*(.tbyte)
		*(.tcommon_byte)
		*(.tdata)
		*(.tbss)
		*(.tcommon)
	} > INTRAM

	.comment 0 : { *(.comment) }
	.debug			0 : { *(.debug) }
	.line			0 : { *(.line) }
	.debug_srcinfo	0 : { *(.debug_srcinfo) }
	.debug_sfnames	0 : { *(.debug_sfnames) }
	.debug_aranges	0 : { *(.debug_aranges) }
	.debug_pubnames 0 : { *(.debug_pubnames) }

}
