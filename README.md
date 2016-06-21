htsuse
======

Some stuff that uses htslib


grabvcf
-------

This is like grabix in that it grabs selected records from a VCF, but it doesn't create/or use an index.
It can also get from a BCF.

To get the first 1K records:
```
	grabvcf $VCF 1 1000
```
