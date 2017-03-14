extern void print_log();
extern void Log(const int line);
/*compare_distance.awk $Revision: 1.6 $ */
/*random_syntax.awk $Revision: 1.22 $ syntax.awk $Revision: 1.39 $ seed=1099 pMaxExpr=1000000 pMinInitExpr=3 pInitExpr=7 pPopSize=1   Tue Feb 07 10:19:58 GMT 2012 */
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
/*     1 <aligner_cache> <aligner_cache_20> 0 <aligner_cache_26> 0 <aligner_cache_27> 0 <aligner_cache_28> 0 <aligner_cache_29> 0 <aligner_cache_30> 0 <aligner_cache_31> 0 <aligner_cache_32> 0 <aligner_cache_33> 0 <aligner_cache_39> 0 <aligner_cache_40> 0 <aligner_cache_41> 0 <aligner_cache_42> 0 <aligner_cache_43> 0 <aligner_cache_50> 0 <aligner_cache_51> 0 <aligner_cache_52> 0 <aligner_cache_53> 0 <aligner_cache_54> 0 <aligner_cache_55> 0 <aligner_cache_57> 0 <aligner_cache_58> 0 <aligner_cache_59> 0 <aligner_cache_60> 0 <aligner_cache_61> 0 <aligner_cache_62> 0 <aligner_cache_63> 0 <aligner_cache_64> 0 <aligner_cache_65> 0 <aligner_cache_66> 0 <aligner_cache_67> 0 <aligner_cache_68> 0 <aligner_cache_69> 0 <aligner_cache_70> 0 <aligner_cache_71> 0 <aligner_cache_72> 0 <aligner_cache_73> 0 <aligner_cache_74> 0 <aligner_cache_76> 0 <aligner_cache_77> 0 <aligner_cache_79> 0 <aligner_cache_80> 0 <aligner_cache_81> 0 <aligner_cache_82> 0 <aligner_cache_83> 0 <aligner_cache_84> 0 <aligner_cache_85> 0 <aligner_cache_86> 0 <aligner_cache_87> 0 <aligner_cache_88> 0 <aligner_cache_89> 0 <aligner_cache_90> 0 <aligner_cache_91> 0 <aligner_cache_94> 0 <aligner_cache_95> 0 <aligner_cache_96> 0 <aligner_cache_97> 0 <aligner_cache_98> 0 <aligner_cache_99> 0 <aligner_cache_100> 0 <aligner_cache_101> 0 <aligner_cache_102> 0 <aligner_cache_103> 0 <aligner_cache_104> 0 <aligner_cache_105> 0 <aligner_cache_106> 0 <aligner_cache_107> 0 <aligner_cache_108> 0 <aligner_cache_109> 0 <aligner_cache_110> 0 <aligner_cache_111> 0 <aligner_cache_112> 0 <aligner_cache_115> 0 <aligner_cache_116> 0 <aligner_cache_121> 0 <aligner_cache_122> 0 <aligner_cache_123> 0 <aligner_cache_124> 0 <aligner_cache_130> 0 <aligner_cache_131> 0 <aligner_cache_132> 0 <aligner_cache_133> 0 <aligner_cache_134> 0 <aligner_cache_135> 0 <aligner_cache_136> 0 <aligner_cache_137> 0 <aligner_cache_138> 0 <aligner_cache_141> 0 <aligner_cache_142> 0 <aligner_cache_143> 0 <aligner_cache_144> 0 <aligner_cache_145> 0 <aligner_cache_146> 0 <aligner_cache_147> 0 <aligner_cache_155> 0 <aligner_cache_156> 0 <aligner_cache_157> 0 <aligner_cache_158> 0 <aligner_cache_159> 0 <aligner_cache_160> 0 <aligner_cache_161> 0 <aligner_cache_162> 0 <aligner_cache_163> 0 <aligner_cache_164> 0 <aligner_cache_165> 0 <aligner_cache_166> 0 <aligner_cache_168> 0 <aligner_cache_169> 0 <aligner_cache_170> 0 <aligner_cache_171> 0 <aligner_cache_172> 0 <aligner_cache_173> 0 <aligner_cache_174> 0 <aligner_cache_175> 0 
*/
#include "aligner_cache.h"
bool QVal::repOk(const AlignmentCache& ac) const {
Log(18560); if(rangen_ > 0) {
; Log(18561);
; Log(18562);
Log(18563); }
; Log(18564);
Log(18565); return true;
Log(18566); }
bool SAVal::repOk(const AlignmentCache& ac) const {
; Log(18573);
; Log(18574);
Log(18575); return true;
Log(18576); }
bool SATuple::randomNarrow(
const EList<SATuple, 16>& src,
EList<SATuple, 16>& dst,
RandomSource& rnd,
const SimpleFunc& rowmult)
{ Log(18588);
size_t totrows = 0;
for(size_t i = 0; i < src.size(); i++) {
totrows += src[i].offs.size(); Log(18592);
Log(18593); }
size_t maxrows = rowmult.f<size_t>((double)totrows);
; Log(18595);
Log(18596); if(totrows <= maxrows) {
Log(18597); return false;
Log(18598); }
size_t totrowsSampled = 0;
uint32_t off = (uint32_t)(rnd.nextU32() % totrows); Log(18600);
bool on = false;
bool done = false;
totrows = 0; Log(18603);
for(int twice = 0; twice < 2; twice++) {
for(size_t i = 0; i < src.size(); i++) {
(static_cast<void> (0)); Log(18606);
Log(18607); if(!on) {
on = (off < totrows + src[i].offs.size()); Log(18609);
Log(18610); if(on) {
; Log(18612);
dst.expand(); Log(18613);
size_t first = off - totrows;
size_t last = first + maxrows;
Log(18616); if(last > src[i].offs.size()) {
last = src[i].offs.size(); Log(18617);
Log(18618); }
; Log(18619);
dst.back().init(src[i], first, last); Log(18620);
totrowsSampled += (last-first); Log(18621);
(static_cast<void> (0)); Log(18622);
Log(18623); }
} else {
; Log(18627);
dst.expand(); Log(18628);
size_t first = 0;
size_t last = maxrows - totrowsSampled;
Log(18631); if(last > src[i].offs.size()) {
last = src[i].offs.size(); Log(18632);
Log(18633); }
; Log(18634);
dst.back().init(src[i], first, last); Log(18635);
totrowsSampled += (last-first); Log(18636);
(static_cast<void> (0)); Log(18637);
Log(18638); }
Log(18639); if(totrowsSampled == maxrows) {
done = true; Log(18640);
Log(18641); break;
Log(18642); }
totrows += src[i].offs.size(); Log(18643);
Log(18644); }
Log(18645); if(done) break;
(static_cast<void> (0)); Log(18648);
Log(18649); }
(static_cast<void> (0)); Log(18654);
; Log(18655);
Log(18656); return true;
Log(18657); }
bool AlignmentCache::addOnTheFly(
QVal& qv,
const SAKey& sak,
uint32_t topf,
uint32_t botf,
bool getLock)
{ Log(18669);
ThreadSafe ts(lockPtr(), shared_ && getLock); Log(18670);
bool added = true;
Log(18674); if(!qv.valid()) {
qv.init((uint32_t)qlist_.size(), 0, 0); Log(18675);
Log(18676); }
qv.addRange(botf-topf); Log(18677);
Log(18678); if(!qlist_.add(pool(), sak)) {
Log(18679); return false;
Log(18680); }
; Log(18688);
SANode *s = samap_.add(pool(), sak, &added); Log(18689);
Log(18690); if(s == __null) {
Log(18691); return false;
Log(18692); }
(static_cast<void> (0)); Log(18693);
Log(18694); if(added) {
s->payload.i = (uint32_t)salist_.size(); Log(18695);
s->payload.len = botf - topf; Log(18696);
s->payload.top = topf; Log(18697);
for(size_t j = 0; j < (botf-topf); j++) {
Log(18699); if(!salist_.add(pool(), 0xffffffff)) {
s->payload.len = (uint32_t)j; Log(18701);
Log(18702); return false;
Log(18703); }
Log(18704); }
(static_cast<void> (0)); Log(18705);
Log(18706); }
Log(18707); return true;
Log(18708); }
