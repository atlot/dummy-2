extern void print_log();
extern void Log(const int line);
/*compare_distance.awk $Revision: 1.6 $ */
/*random_syntax.awk $Revision: 1.22 $ syntax.awk $Revision: 1.39 $ seed=1099 pMaxExpr=1000000 pMinInitExpr=3 pInitExpr=7 pPopSize=1   Tue Feb 07 10:23:18 GMT 2012 */
/* #pre_syntax.awk Revision: 1.18  gismo.cpp Tue Feb 07 10:10:08 GMT 2012 bowtie2.bnf_G */
/* #create_syntax.awk Revision: 1.51  Mon Jan 30 14:31:16 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "bt2_search.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "ccnt_lut.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "ref_read.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "alphabet.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "shmem.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "edit.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "bt2_idx.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "bt2_io.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "bt2_util.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "reference.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "ds.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "multikey_qsort.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "qual.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "pat.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "log.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "sam.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "color.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "color_dec.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "read_qseq.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_seed_policy.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_seed.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_sw.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_sw_col.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_sw_driver.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_cache.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_result.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "ref_coord.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "mask.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "pe.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aln_sink.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "dp_framer.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "scoring.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "sa_rescomb.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "seed_scan.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "presets.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_swsse.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_swsse_loc_i16.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_swsse_ee_i16.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_swsse_loc_u8.cpp" Mon Jan 30 14:14:20 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "aligner_swsse_ee_u8.cpp" Mon Jan 30 14:14:20 GMT 2012 bowtie2.bnf_G */
/* #clean_cpp.awk Revision: 1.2  "bowtie_main.cpp" Mon Jan 30 14:14:20 GMT 2012 bowtie2.bnf_G */
/*     1 <seed_scan> <seed_scan_27> 0 
*/
#include "seed_scan.h"
