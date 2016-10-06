
SOURCES := ../../samtools/sample.c ../../samtools/bedidx.c \
	    ../../samtools/sam_utils.c \
	    ../../samtools/sam_opts.c \
	    ../../samtools/bam_plcmd.c \
	    ../../samtools/bam2bcf.c \
	    ../../samtools/bam2bcf_indel.c \
	    ../../samtools/samtools.h \


bam2depth:
	$(CC) -I../../htslib/ -I../../samtools -L../../htslib/ -L../../samtools $(SOURCES) bam2depth.c -lm -lz -lhts -o bam2depth
