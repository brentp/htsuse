#include <stdio.h>
#include <htslib/vcf.h>
#include <htslib/hts.h>
#include <htslib/kstring.h>

int main(int argc, char **argv){

	char *fname = argv[1];
	int idxStart = atoi(argv[2]);
	int idxEnd = atoi(argv[3]);
	int j = 1;
	htsFile *fp = hts_open(fname, "rb");
	bcf_hdr_t *hdr = bcf_hdr_read(fp);

	bcf1_t *rec = bcf_init();
	if(idxStart < 1){
		idxStart = 1;
	}

	htsFile * out = hts_open("-", "w");
	bcf_hdr_write(out, hdr);
	while (bcf_read1(fp, hdr, rec) >=0) {
		if(j >= idxStart) {
			bcf_write1(out, hdr, rec);
		}
		if(j == idxEnd){
			break;
		}
		j += 1;
	}
	hts_close(fp);
	bcf_destroy(rec);
	exit(hts_close(out));
}
