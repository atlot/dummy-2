#include "bowtie_main_H.h"
extern void print_log();
extern bool ON(const int line);
/*compare_distance.awk $Revision: 1.6 $ */
/*random_syntax.awk $Revision: 1.22 $ syntax.awk $Revision: 1.39 $ seed=1099 pMaxExpr=1000000 pMinInitExpr=3 pInitExpr=7 pPopSize=1   Wed Mar 07 19:10:41 GMT 2012 */
/* #pre_syntax2.awk Revision: 1.51  gismo_H.cpp Wed Mar 07 18:06:36 GMT 2012 bowtie2.bnf_H */
/* #create_syntax.awk Revision: 1.51  Mon Jan 30 14:31:16 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "bt2_search.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "ccnt_lut.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "ref_read.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "alphabet.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "shmem.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "edit.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "bt2_idx.cpp" Mon Jan 30 14:14:15 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "bt2_io.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "bt2_util.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "reference.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "ds.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "multikey_qsort.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "qual.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "pat.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "log.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "sam.cpp" Mon Jan 30 14:14:16 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "color.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "color_dec.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "read_qseq.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_seed_policy.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_seed.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_sw.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_sw_col.cpp" Mon Jan 30 14:14:17 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_sw_driver.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_cache.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_result.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "ref_coord.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "mask.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "pe.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aln_sink.cpp" Mon Jan 30 14:14:18 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "dp_framer.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "scoring.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "sa_rescomb.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "seed_scan.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "presets.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_swsse.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_swsse_loc_i16.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_swsse_ee_i16.cpp" Mon Jan 30 14:14:19 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_swsse_loc_u8.cpp" Mon Jan 30 14:14:20 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "aligner_swsse_ee_u8.cpp" Mon Jan 30 14:14:20 GMT 2012 bowtie2.bnf_H */
/* #clean_cpp.awk Revision: 1.2  "bowtie_main.cpp" Mon Jan 30 14:14:20 GMT 2012 bowtie2.bnf_H */
/*     1 <bowtie_main> <bowtie_main_20> 0 <bowtie_main_21> 0 <bowtie_main_22> 0 <bowtie_main_23> 0 <bowtie_main_24> 0 <bowtie_main_25> 0 <bowtie_main_27> 0 <bowtie_main_29> 0 <bowtie_main_30> 0 <bowtie_main_31> 0 <bowtie_main_42> 0 <bowtie_main_43> 0 <bowtie_main_44> 0 <bowtie_main_45> 0 <bowtie_main_46> 0 <bowtie_main_47> 0 <bowtie_main_48> 0 <bowtie_main_49> 0 <bowtie_main_50> 0 <bowtie_main_51> 0 <bowtie_main_52> 0 <bowtie_main_53> 0 <bowtie_main_54> 0 <bowtie_main_55> 0 <bowtie_main_56> 0 <bowtie_main_57> 0 <bowtie_main_58> 0 <bowtie_main_59> 0 <bowtie_main_60> 0 <bowtie_main_61> 0 <bowtie_main_62> 0 <bowtie_main_63> 0 <bowtie_main_64> 0 <bowtie_main_65> 0 <bowtie_main_66> 0 <bowtie_main_67> 0 <bowtie_main_68> 0 <bowtie_main_69> 0 
*/
//#include <iostream>
//#include <fstream>
//#include <string.h>
//#include <stdlib.h>
//#include "tokenize.h"
//#include "ds.h"
using namespace std;
extern "C" {
int bowtie(int argc, const char **argv);
}
int main(int argc, const char **argv) {
if(ON(29823)) if(argc > 2 && strcmp(argv[1], "-A") == 0) {
const char *file = argv[2];
ifstream in;
if(ON(29826)){in.open(file);};
char buf[4096];
int lastret = -1;
while(in.getline(buf, 4095)) {
EList<string> args;
if(ON(29831)){args.push_back(string(argv[0]));};
if(ON(29832)){tokenize(buf, " \t", args);};
const char **myargs = (const char**)malloc(sizeof(char*)*args.size());
for(size_t i = 0; i < args.size(); i++) {
if(ON(29835)){myargs[i] = args[i].c_str();};
}
if(ON(29837)) if(args.size() == 1) continue;
if(ON(29838)){lastret = bowtie((int)args.size(), myargs);};
if(ON(29839)){free(myargs);};
}
if(ON(29841)) if(lastret == -1) {
if(ON(29842)) cerr << "Warning: No arg strings parsed from " << file << endl;
return 0;
}
return lastret;
} else {
return bowtie(argc, argv);
}
}
