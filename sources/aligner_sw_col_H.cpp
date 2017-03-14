#include "aligner_sw_col_H.h"
extern void print_log();
extern bool ON(const int line);
/*compare_distance.awk $Revision: 1.6 $ */
/*random_syntax.awk $Revision: 1.22 $ syntax.awk $Revision: 1.39 $ seed=1099 pMaxExpr=1000000 pMinInitExpr=3 pInitExpr=7 pPopSize=1   Wed Mar 07 19:04:27 GMT 2012 */
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
/*     1 <aligner_sw_col> <aligner_sw_col_20> 0 <aligner_sw_col_21> 0 <aligner_sw_col_22> 0 <aligner_sw_col_23> 0 <aligner_sw_col_24> 0 <aligner_sw_col_25> 0 <aligner_sw_col_35> 0 <aligner_sw_col_36> 0 <aligner_sw_col_37> 0 <aligner_sw_col_38> 0 <aligner_sw_col_39> 0 <aligner_sw_col_40> 0 <aligner_sw_col_41> 0 <aligner_sw_col_42> 0 <aligner_sw_col_43> 0 <aligner_sw_col_44> 0 <aligner_sw_col_45> 0 <aligner_sw_col_46> 0 <aligner_sw_col_47> 0 <aligner_sw_col_48> 0 <aligner_sw_col_50> 0 <aligner_sw_col_51> 0 <aligner_sw_col_52> 0 <aligner_sw_col_53> 0 <aligner_sw_col_54> 0 <aligner_sw_col_55> 0 <aligner_sw_col_58> 0 <aligner_sw_col_59> 0 <aligner_sw_col_60> 0 <aligner_sw_col_61> 0 <aligner_sw_col_67> 0 <aligner_sw_col_69> 0 <aligner_sw_col_70> 0 <aligner_sw_col_71> 0 <aligner_sw_col_72> 0 <aligner_sw_col_73> 0 <aligner_sw_col_74> 0 <aligner_sw_col_75> 0 <aligner_sw_col_76> 0 <aligner_sw_col_77> 0 <aligner_sw_col_78> 0 <aligner_sw_col_79> 0 <aligner_sw_col_80> 0 <aligner_sw_col_81> 0 <aligner_sw_col_82> 0 <aligner_sw_col_83> 0 <aligner_sw_col_84> 0 <aligner_sw_col_85> 0 <aligner_sw_col_86> 0 <aligner_sw_col_87> 0 <aligner_sw_col_88> 0 <aligner_sw_col_89> 0 <aligner_sw_col_90> 0 <aligner_sw_col_91> 0 <aligner_sw_col_92> 0 <aligner_sw_col_102> 0 <aligner_sw_col_103> 0 <aligner_sw_col_104> 0 <aligner_sw_col_105> 0 <aligner_sw_col_106> 0 <aligner_sw_col_107> 0 <aligner_sw_col_108> 0 <aligner_sw_col_109> 0 <aligner_sw_col_110> 0 <aligner_sw_col_111> 0 <aligner_sw_col_112> 0 <aligner_sw_col_114> 0 <aligner_sw_col_117> 0 <aligner_sw_col_118> 0 <aligner_sw_col_119> 0 <aligner_sw_col_121> 0 <aligner_sw_col_122> 0 <aligner_sw_col_123> 0 <aligner_sw_col_124> 0 <aligner_sw_col_125> 0 <aligner_sw_col_126> 0 <aligner_sw_col_127> 0 <aligner_sw_col_128> 0 <aligner_sw_col_129> 0 <aligner_sw_col_130> 0 <aligner_sw_col_140> 0 <aligner_sw_col_141> 0 <aligner_sw_col_142> 0 <aligner_sw_col_143> 0 <aligner_sw_col_144> 0 <aligner_sw_col_145> 0 <aligner_sw_col_146> 0 <aligner_sw_col_147> 0 <aligner_sw_col_148> 0 <aligner_sw_col_149> 0 <aligner_sw_col_150> 0 <aligner_sw_col_152> 0 <aligner_sw_col_153> 0 <aligner_sw_col_154> 0 <aligner_sw_col_157> 0 <aligner_sw_col_158> 0 <aligner_sw_col_159> 0 <aligner_sw_col_161> 0 <aligner_sw_col_162> 0 <aligner_sw_col_163> 0 <aligner_sw_col_164> 0 <aligner_sw_col_165> 0 <aligner_sw_col_166> 0 <aligner_sw_col_167> 0 <aligner_sw_col_168> 0 <aligner_sw_col_169> 0 <aligner_sw_col_170> 0 <aligner_sw_col_171> 0 <aligner_sw_col_172> 0 <aligner_sw_col_177> 0 <aligner_sw_col_178> 0 <aligner_sw_col_179> 0 <aligner_sw_col_180> 0 <aligner_sw_col_181> 0 <aligner_sw_col_182> 0 <aligner_sw_col_183> 0 <aligner_sw_col_184> 0 <aligner_sw_col_186> 0 <aligner_sw_col_188> 0 <aligner_sw_col_190> 0 <aligner_sw_col_191> 0 <aligner_sw_col_192> 0 <aligner_sw_col_193> 0 <aligner_sw_col_194> 0 <aligner_sw_col_223> 0 <aligner_sw_col_224> 0 <aligner_sw_col_225> 0 <aligner_sw_col_226> 0 <aligner_sw_col_227> 0 <aligner_sw_col_228> 0 <aligner_sw_col_229> 0 <aligner_sw_col_230> 0 <aligner_sw_col_231> 0 <aligner_sw_col_232> 0 <aligner_sw_col_233> 0 <aligner_sw_col_234> 0 <aligner_sw_col_235> 0 <aligner_sw_col_236> 0 <aligner_sw_col_237> 0 <aligner_sw_col_238> 0 <aligner_sw_col_239> 0 <aligner_sw_col_240> 0 <aligner_sw_col_241> 0 <aligner_sw_col_242> 0 <aligner_sw_col_243> 0 <aligner_sw_col_244> 0 <aligner_sw_col_245> 0 <aligner_sw_col_246> 0 <aligner_sw_col_247> 0 <aligner_sw_col_248> 0 <aligner_sw_col_250> 0 <aligner_sw_col_251> 0 <aligner_sw_col_252> 0 <aligner_sw_col_253> 0 <aligner_sw_col_254> 0 <aligner_sw_col_255> 0 <aligner_sw_col_256> 0 <aligner_sw_col_257> 0 <aligner_sw_col_258> 0 <aligner_sw_col_259> 0 <aligner_sw_col_260> 0 <aligner_sw_col_261> 0 <aligner_sw_col_262> 0 <aligner_sw_col_263> 0 <aligner_sw_col_264> 0 <aligner_sw_col_265> 0 <aligner_sw_col_266> 0 <aligner_sw_col_267> 0 <aligner_sw_col_268> 0 <aligner_sw_col_269> 0 <aligner_sw_col_271> 0 <aligner_sw_col_272> 0 <aligner_sw_col_274> 0 <aligner_sw_col_275> 0 <aligner_sw_col_276> 0 <aligner_sw_col_278> 0 <aligner_sw_col_279> 0 <aligner_sw_col_280> 0 <aligner_sw_col_281> 0 <aligner_sw_col_282> 0 <aligner_sw_col_283> 0 <aligner_sw_col_284> 0 <aligner_sw_col_285> 0 <aligner_sw_col_286> 0 <aligner_sw_col_287> 0 <aligner_sw_col_288> 0 <aligner_sw_col_289> 0 <aligner_sw_col_290> 0 <aligner_sw_col_292> 0 <aligner_sw_col_293> 0 <aligner_sw_col_294> 0 <aligner_sw_col_295> 0 <aligner_sw_col_296> 0 <aligner_sw_col_297> 0 <aligner_sw_col_298> 0 <aligner_sw_col_299> 0 <aligner_sw_col_300> 0 <aligner_sw_col_301> 0 <aligner_sw_col_302> 0 <aligner_sw_col_303> 0 <aligner_sw_col_304> 0 <aligner_sw_col_305> 0 <aligner_sw_col_307> 0 <aligner_sw_col_308> 0 <aligner_sw_col_309> 0 <aligner_sw_col_310> 0 <aligner_sw_col_311> 0 <aligner_sw_col_312> 0 <aligner_sw_col_313> 0 <aligner_sw_col_314> 0 <aligner_sw_col_315> 0 <aligner_sw_col_317> 0 <aligner_sw_col_318> 0 <aligner_sw_col_319> 0 <aligner_sw_col_320> 0 <aligner_sw_col_321> 0 <aligner_sw_col_322> 0 <aligner_sw_col_323> 0 <aligner_sw_col_324> 0 <aligner_sw_col_325> 0 <aligner_sw_col_326> 0 <aligner_sw_col_327> 0 <aligner_sw_col_328> 0 <aligner_sw_col_329> 0 <aligner_sw_col_330> 0 <aligner_sw_col_332> 0 <aligner_sw_col_333> 0 <aligner_sw_col_334> 0 <aligner_sw_col_335> 0 <aligner_sw_col_336> 0 <aligner_sw_col_337> 0 <aligner_sw_col_338> 0 <aligner_sw_col_343> 0 <aligner_sw_col_344> 0 <aligner_sw_col_345> 0 <aligner_sw_col_346> 0 <aligner_sw_col_348> 0 <aligner_sw_col_349> 0 <aligner_sw_col_350> 0 <aligner_sw_col_351> 0 <aligner_sw_col_352> 0 <aligner_sw_col_353> 0 <aligner_sw_col_354> 0 <aligner_sw_col_355> 0 <aligner_sw_col_356> 0 <aligner_sw_col_357> 0 <aligner_sw_col_358> 0 <aligner_sw_col_359> 0 <aligner_sw_col_360> 0 <aligner_sw_col_361> 0 <aligner_sw_col_362> 0 <aligner_sw_col_363> 0 <aligner_sw_col_364> 0 <aligner_sw_col_365> 0 <aligner_sw_col_366> 0 <aligner_sw_col_367> 0 <aligner_sw_col_368> 0 <aligner_sw_col_369> 0 <aligner_sw_col_370> 0 <aligner_sw_col_371> 0 <aligner_sw_col_373> 0 <aligner_sw_col_374> 0 <aligner_sw_col_375> 0 <aligner_sw_col_376> 0 <aligner_sw_col_377> 0 <aligner_sw_col_378> 0 <aligner_sw_col_379> 0 <aligner_sw_col_380> 0 <aligner_sw_col_381> 0 <aligner_sw_col_382> 0 <aligner_sw_col_383> 0 <aligner_sw_col_384> 0 <aligner_sw_col_385> 0 <aligner_sw_col_386> 0 <aligner_sw_col_387> 0 <aligner_sw_col_388> 0 <aligner_sw_col_389> 0 <aligner_sw_col_390> 0 <aligner_sw_col_391> 0 <aligner_sw_col_392> 0 <aligner_sw_col_393> 0 <aligner_sw_col_394> 0 <aligner_sw_col_395> 0 <aligner_sw_col_396> 0 <aligner_sw_col_399> 0 <aligner_sw_col_400> 0 <aligner_sw_col_401> 0 <aligner_sw_col_402> 0 <aligner_sw_col_403> 0 <aligner_sw_col_404> 0 <aligner_sw_col_405> 0 <aligner_sw_col_406> 0 <aligner_sw_col_407> 0 <aligner_sw_col_408> 0 <aligner_sw_col_409> 0 <aligner_sw_col_410> 0 <aligner_sw_col_411> 0 <aligner_sw_col_412> 0 <aligner_sw_col_414> 0 <aligner_sw_col_415> 0 <aligner_sw_col_416> 0 <aligner_sw_col_417> 0 <aligner_sw_col_418> 0 <aligner_sw_col_419> 0 <aligner_sw_col_420> 0 <aligner_sw_col_421> 0 <aligner_sw_col_422> 0 <aligner_sw_col_423> 0 <aligner_sw_col_424> 0 <aligner_sw_col_425> 0 <aligner_sw_col_426> 0 <aligner_sw_col_427> 0 <aligner_sw_col_428> 0 <aligner_sw_col_429> 0 <aligner_sw_col_430> 0 <aligner_sw_col_431> 0 <aligner_sw_col_432> 0 <aligner_sw_col_433> 0 <aligner_sw_col_434> 0 <aligner_sw_col_435> 0 <aligner_sw_col_436> 0 <aligner_sw_col_437> 0 <aligner_sw_col_438> 0 <aligner_sw_col_439> 0 <aligner_sw_col_440> 0 <aligner_sw_col_441> 0 <aligner_sw_col_444> 0 <aligner_sw_col_445> 0 <aligner_sw_col_446> 0 <aligner_sw_col_447> 0 <aligner_sw_col_448> 0 <aligner_sw_col_449> 0 <aligner_sw_col_450> 0 <aligner_sw_col_451> 0 <aligner_sw_col_452> 0 <aligner_sw_col_453> 0 <aligner_sw_col_454> 0 <aligner_sw_col_455> 0 <aligner_sw_col_456> 0 <aligner_sw_col_457> 0 <aligner_sw_col_459> 0 <aligner_sw_col_460> 0 <aligner_sw_col_461> 0 <aligner_sw_col_462> 0 <aligner_sw_col_463> 0 <aligner_sw_col_464> 0 <aligner_sw_col_465> 0 <aligner_sw_col_466> 0 <aligner_sw_col_467> 0 <aligner_sw_col_468> 0 <aligner_sw_col_469> 0 <aligner_sw_col_470> 0 <aligner_sw_col_471> 0 <aligner_sw_col_472> 0 <aligner_sw_col_473> 0 <aligner_sw_col_474> 0 <aligner_sw_col_475> 0 <aligner_sw_col_476> 0 <aligner_sw_col_477> 0 <aligner_sw_col_478> 0 <aligner_sw_col_479> 0 <aligner_sw_col_480> 0 <aligner_sw_col_481> 0 <aligner_sw_col_482> 0 <aligner_sw_col_483> 0 <aligner_sw_col_484> 0 <aligner_sw_col_485> 0 <aligner_sw_col_486> 0 <aligner_sw_col_487> 0 <aligner_sw_col_488> 0 <aligner_sw_col_489> 0 <aligner_sw_col_490> 0 <aligner_sw_col_491> 0 <aligner_sw_col_492> 0 <aligner_sw_col_493> 0 <aligner_sw_col_494> 0 <aligner_sw_col_495> 0 <aligner_sw_col_496> 0 <aligner_sw_col_497> 0 <aligner_sw_col_498> 0 <aligner_sw_col_499> 0 <aligner_sw_col_500> 0 <aligner_sw_col_501> 0 <aligner_sw_col_502> 0 <aligner_sw_col_503> 0 <aligner_sw_col_504> 0 <aligner_sw_col_505> 0 <aligner_sw_col_506> 0 <aligner_sw_col_507> 0 <aligner_sw_col_508> 0 <aligner_sw_col_509> 0 <aligner_sw_col_510> 0 <aligner_sw_col_511> 0 <aligner_sw_col_512> 0 <aligner_sw_col_513> 0 <aligner_sw_col_514> 0 <aligner_sw_col_515> 0 <aligner_sw_col_516> 0 <aligner_sw_col_517> 0 <aligner_sw_col_518> 0 <aligner_sw_col_519> 0 <aligner_sw_col_520> 0 <aligner_sw_col_521> 0 <aligner_sw_col_522> 0 <aligner_sw_col_523> 0 <aligner_sw_col_524> 0 <aligner_sw_col_525> 0 <aligner_sw_col_526> 0 <aligner_sw_col_527> 0 <aligner_sw_col_528> 0 <aligner_sw_col_529> 0 <aligner_sw_col_530> 0 <aligner_sw_col_531> 0 <aligner_sw_col_532> 0 <aligner_sw_col_533> 0 <aligner_sw_col_534> 0 <aligner_sw_col_535> 0 <aligner_sw_col_536> 0 <aligner_sw_col_537> 0 <aligner_sw_col_538> 0 <aligner_sw_col_539> 0 <aligner_sw_col_540> 0 <aligner_sw_col_541> 0 <aligner_sw_col_542> 0 <aligner_sw_col_543> 0 <aligner_sw_col_546> 0 <aligner_sw_col_547> 0 <aligner_sw_col_548> 0 <aligner_sw_col_549> 0 <aligner_sw_col_550> 0 <aligner_sw_col_551> 0 <aligner_sw_col_552> 0 <aligner_sw_col_553> 0 <aligner_sw_col_554> 0 <aligner_sw_col_555> 0 <aligner_sw_col_556> 0 <aligner_sw_col_557> 0 <aligner_sw_col_558> 0 <aligner_sw_col_559> 0 <aligner_sw_col_560> 0 <aligner_sw_col_561> 0 <aligner_sw_col_562> 0 <aligner_sw_col_563> 0 <aligner_sw_col_564> 0 <aligner_sw_col_565> 0 <aligner_sw_col_566> 0 <aligner_sw_col_568> 0 <aligner_sw_col_569> 0 <aligner_sw_col_570> 0 <aligner_sw_col_571> 0 <aligner_sw_col_572> 0 <aligner_sw_col_573> 0 <aligner_sw_col_574> 0 <aligner_sw_col_602> 0 <aligner_sw_col_603> 0 <aligner_sw_col_605> 0 <aligner_sw_col_606> 0 <aligner_sw_col_607> 0 <aligner_sw_col_608> 0 <aligner_sw_col_609> 0 <aligner_sw_col_610> 0 <aligner_sw_col_611> 0 <aligner_sw_col_612> 0 <aligner_sw_col_613> 0 <aligner_sw_col_614> 0 <aligner_sw_col_615> 0 <aligner_sw_col_616> 0 <aligner_sw_col_617> 0 <aligner_sw_col_618> 0 <aligner_sw_col_619> 0 <aligner_sw_col_620> 0 <aligner_sw_col_621> 0 <aligner_sw_col_622> 0 <aligner_sw_col_623> 0 <aligner_sw_col_624> 0 <aligner_sw_col_625> 0 <aligner_sw_col_626> 0 <aligner_sw_col_627> 0 <aligner_sw_col_628> 0 <aligner_sw_col_629> 0 <aligner_sw_col_649> 0 <aligner_sw_col_650> 0 <aligner_sw_col_651> 0 <aligner_sw_col_652> 0 <aligner_sw_col_653> 0 <aligner_sw_col_654> 0 <aligner_sw_col_655> 0 <aligner_sw_col_656> 0 <aligner_sw_col_657> 0 <aligner_sw_col_658> 0 <aligner_sw_col_659> 0 <aligner_sw_col_660> 0 <aligner_sw_col_661> 0 <aligner_sw_col_662> 0 <aligner_sw_col_663> 0 <aligner_sw_col_664> 0 <aligner_sw_col_665> 0 <aligner_sw_col_666> 0 <aligner_sw_col_667> 0 <aligner_sw_col_668> 0 <aligner_sw_col_669> 0 <aligner_sw_col_670> 0 <aligner_sw_col_671> 0 <aligner_sw_col_673> 0 <aligner_sw_col_674> 0 <aligner_sw_col_675> 0 <aligner_sw_col_676> 0 <aligner_sw_col_677> 0 <aligner_sw_col_678> 0 <aligner_sw_col_679> 0 <aligner_sw_col_680> 0 <aligner_sw_col_681> 0 <aligner_sw_col_682> 0 <aligner_sw_col_683> 0 <aligner_sw_col_684> 0 <aligner_sw_col_685> 0 <aligner_sw_col_686> 0 <aligner_sw_col_687> 0 <aligner_sw_col_688> 0 <aligner_sw_col_689> 0 <aligner_sw_col_691> 0 <aligner_sw_col_692> 0 <aligner_sw_col_693> 0 <aligner_sw_col_694> 0 <aligner_sw_col_695> 0 <aligner_sw_col_696> 0 <aligner_sw_col_697> 0 <aligner_sw_col_698> 0 <aligner_sw_col_699> 0 <aligner_sw_col_700> 0 <aligner_sw_col_701> 0 <aligner_sw_col_702> 0 <aligner_sw_col_703> 0 <aligner_sw_col_704> 0 <aligner_sw_col_705> 0 <aligner_sw_col_706> 0 <aligner_sw_col_707> 0 <aligner_sw_col_708> 0 <aligner_sw_col_709> 0 <aligner_sw_col_715> 0 <aligner_sw_col_716> 0 <aligner_sw_col_717> 0 <aligner_sw_col_718> 0 <aligner_sw_col_719> 0 <aligner_sw_col_720> 0 <aligner_sw_col_721> 0 <aligner_sw_col_722> 0 <aligner_sw_col_723> 0 <aligner_sw_col_727> 0 <aligner_sw_col_728> 0 <aligner_sw_col_729> 0 <aligner_sw_col_730> 0 <aligner_sw_col_731> 0 <aligner_sw_col_732> 0 <aligner_sw_col_734> 0 <aligner_sw_col_736> 0 <aligner_sw_col_737> 0 <aligner_sw_col_738> 0 <aligner_sw_col_739> 0 <aligner_sw_col_740> 0 <aligner_sw_col_741> 0 <aligner_sw_col_742> 0 <aligner_sw_col_743> 0 <aligner_sw_col_744> 0 <aligner_sw_col_745> 0 <aligner_sw_col_746> 0 <aligner_sw_col_747> 0 <aligner_sw_col_748> 0 <aligner_sw_col_749> 0 <aligner_sw_col_750> 0 <aligner_sw_col_751> 0 <aligner_sw_col_752> 0 <aligner_sw_col_753> 0 <aligner_sw_col_754> 0 <aligner_sw_col_756> 0 <aligner_sw_col_757> 0 <aligner_sw_col_758> 0 <aligner_sw_col_759> 0 <aligner_sw_col_760> 0 <aligner_sw_col_761> 0 <aligner_sw_col_762> 0 <aligner_sw_col_763> 0 <aligner_sw_col_764> 0 <aligner_sw_col_765> 0 <aligner_sw_col_766> 0 <aligner_sw_col_767> 0 <aligner_sw_col_768> 0 <aligner_sw_col_769> 0 <aligner_sw_col_770> 0 <aligner_sw_col_771> 0 <aligner_sw_col_772> 0 <aligner_sw_col_774> 0 <aligner_sw_col_775> 0 <aligner_sw_col_776> 0 <aligner_sw_col_777> 0 <aligner_sw_col_778> 0 <aligner_sw_col_779> 0 <aligner_sw_col_780> 0 <aligner_sw_col_781> 0 <aligner_sw_col_782> 0 <aligner_sw_col_783> 0 <aligner_sw_col_784> 0 <aligner_sw_col_785> 0 <aligner_sw_col_786> 0 <aligner_sw_col_787> 0 <aligner_sw_col_788> 0 <aligner_sw_col_789> 0 <aligner_sw_col_790> 0 <aligner_sw_col_791> 0 <aligner_sw_col_792> 0 <aligner_sw_col_793> 0 <aligner_sw_col_799> 0 <aligner_sw_col_800> 0 <aligner_sw_col_801> 0 <aligner_sw_col_802> 0 <aligner_sw_col_803> 0 <aligner_sw_col_804> 0 <aligner_sw_col_805> 0 <aligner_sw_col_806> 0 <aligner_sw_col_807> 0 <aligner_sw_col_808> 0 <aligner_sw_col_809> 0 <aligner_sw_col_812> 0 <aligner_sw_col_814> 0 <aligner_sw_col_816> 0 <aligner_sw_col_817> 0 <aligner_sw_col_818> 0 <aligner_sw_col_819> 0 <aligner_sw_col_820> 0 <aligner_sw_col_821> 0 <aligner_sw_col_822> 0 <aligner_sw_col_823> 0 <aligner_sw_col_824> 0 <aligner_sw_col_825> 0 <aligner_sw_col_827> 0 <aligner_sw_col_828> 0 <aligner_sw_col_829> 0 <aligner_sw_col_830> 0 <aligner_sw_col_831> 0 <aligner_sw_col_832> 0 <aligner_sw_col_833> 0 <aligner_sw_col_834> 0 <aligner_sw_col_835> 0 <aligner_sw_col_836> 0 <aligner_sw_col_837> 0 <aligner_sw_col_838> 0 <aligner_sw_col_839> 0 <aligner_sw_col_840> 0 <aligner_sw_col_841> 0 <aligner_sw_col_842> 0 <aligner_sw_col_843> 0 <aligner_sw_col_844> 0 <aligner_sw_col_845> 0 <aligner_sw_col_846> 0 <aligner_sw_col_847> 0 <aligner_sw_col_848> 0 <aligner_sw_col_849> 0 <aligner_sw_col_920> 0 <aligner_sw_col_921> 0 <aligner_sw_col_922> 0 <aligner_sw_col_923> 0 <aligner_sw_col_924> 0 <aligner_sw_col_925> 0 <aligner_sw_col_926> 0 <aligner_sw_col_927> 0 <aligner_sw_col_928> 0 <aligner_sw_col_937> 0 <aligner_sw_col_938> 0 <aligner_sw_col_939> 0 <aligner_sw_col_940> 0 <aligner_sw_col_941> 0 <aligner_sw_col_943> 0 <aligner_sw_col_944> 0 <aligner_sw_col_949> 0 <aligner_sw_col_950> 0 <aligner_sw_col_951> 0 <aligner_sw_col_952> 0 <aligner_sw_col_953> 0 <aligner_sw_col_955> 0 <aligner_sw_col_960> 0 <aligner_sw_col_961> 0 <aligner_sw_col_962> 0 <aligner_sw_col_963> 0 <aligner_sw_col_964> 0 <aligner_sw_col_965> 0 <aligner_sw_col_966> 0 <aligner_sw_col_967> 0 <aligner_sw_col_970> 0 <aligner_sw_col_971> 0 <aligner_sw_col_972> 0 <aligner_sw_col_973> 0 <aligner_sw_col_974> 0 <aligner_sw_col_975> 0 <aligner_sw_col_976> 0 <aligner_sw_col_979> 0 <aligner_sw_col_980> 0 <aligner_sw_col_981> 0 <aligner_sw_col_982> 0 <aligner_sw_col_983> 0 <aligner_sw_col_985> 0 <aligner_sw_col_986> 0 <aligner_sw_col_987> 0 <aligner_sw_col_988> 0 <aligner_sw_col_989> 0 <aligner_sw_col_991> 0 <aligner_sw_col_992> 0 <aligner_sw_col_993> 0 <aligner_sw_col_995> 0 <aligner_sw_col_996> 0 <aligner_sw_col_997> 0 <aligner_sw_col_998> 0 <aligner_sw_col_999> 0 <aligner_sw_col_1000> 0 <aligner_sw_col_1001> 0 <aligner_sw_col_1002> 0 <aligner_sw_col_1003> 0 <aligner_sw_col_1004> 0 <aligner_sw_col_1005> 0 <aligner_sw_col_1012> 0 <aligner_sw_col_1013> 0 <aligner_sw_col_1014> 0 <aligner_sw_col_1015> 0 <aligner_sw_col_1016> 0 <aligner_sw_col_1017> 0 <aligner_sw_col_1018> 0 <aligner_sw_col_1019> 0 <aligner_sw_col_1020> 0 <aligner_sw_col_1021> 0 <aligner_sw_col_1022> 0 <aligner_sw_col_1023> 0 <aligner_sw_col_1024> 0 <aligner_sw_col_1025> 0 <aligner_sw_col_1026> 0 <aligner_sw_col_1027> 0 <aligner_sw_col_1033> 0 <aligner_sw_col_1034> 0 <aligner_sw_col_1035> 0 <aligner_sw_col_1036> 0 <aligner_sw_col_1037> 0 <aligner_sw_col_1038> 0 <aligner_sw_col_1039> 0 <aligner_sw_col_1040> 0 <aligner_sw_col_1041> 0 <aligner_sw_col_1042> 0 <aligner_sw_col_1043> 0 <aligner_sw_col_1044> 0 <aligner_sw_col_1045> 0 <aligner_sw_col_1046> 0 <aligner_sw_col_1047> 0 <aligner_sw_col_1048> 0 <aligner_sw_col_1049> 0 <aligner_sw_col_1050> 0 <aligner_sw_col_1051> 0 <aligner_sw_col_1052> 0 <aligner_sw_col_1053> 0 <aligner_sw_col_1054> 0 <aligner_sw_col_1055> 0 <aligner_sw_col_1057> 0 <aligner_sw_col_1059> 0 <aligner_sw_col_1060> 0 <aligner_sw_col_1061> 0 <aligner_sw_col_1062> 0 <aligner_sw_col_1063> 0 <aligner_sw_col_1064> 0 <aligner_sw_col_1065> 0 <aligner_sw_col_1066> 0 <aligner_sw_col_1072> 0 <aligner_sw_col_1073> 0 <aligner_sw_col_1074> 0 <aligner_sw_col_1075> 0 <aligner_sw_col_1076> 0 <aligner_sw_col_1077> 0 <aligner_sw_col_1078> 0 <aligner_sw_col_1079> 0 <aligner_sw_col_1080> 0 <aligner_sw_col_1081> 0 <aligner_sw_col_1082> 0 <aligner_sw_col_1083> 0 <aligner_sw_col_1084> 0 <aligner_sw_col_1085> 0 <aligner_sw_col_1087> 0 <aligner_sw_col_1088> 0 <aligner_sw_col_1089> 0 <aligner_sw_col_1090> 0 <aligner_sw_col_1091> 0 <aligner_sw_col_1092> 0 <aligner_sw_col_1093> 0 <aligner_sw_col_1095> 0 <aligner_sw_col_1096> 0 <aligner_sw_col_1102> 0 <aligner_sw_col_1103> 0 <aligner_sw_col_1104> 0 <aligner_sw_col_1105> 0 <aligner_sw_col_1106> 0 <aligner_sw_col_1107> 0 <aligner_sw_col_1108> 0 <aligner_sw_col_1109> 0 <aligner_sw_col_1110> 0 <aligner_sw_col_1111> 0 <aligner_sw_col_1112> 0 <aligner_sw_col_1113> 0 <aligner_sw_col_1114> 0 <aligner_sw_col_1115> 0 <aligner_sw_col_1116> 0 <aligner_sw_col_1117> 0 <aligner_sw_col_1118> 0 <aligner_sw_col_1119> 0 <aligner_sw_col_1120> 0 <aligner_sw_col_1121> 0 <aligner_sw_col_1122> 0 <aligner_sw_col_1123> 0 <aligner_sw_col_1124> 0 <aligner_sw_col_1125> 0 <aligner_sw_col_1126> 0 <aligner_sw_col_1127> 0 <aligner_sw_col_1129> 0 <aligner_sw_col_1130> 0 <aligner_sw_col_1131> 0 <aligner_sw_col_1132> 0 <aligner_sw_col_1133> 0 <aligner_sw_col_1134> 0 <aligner_sw_col_1135> 0 <aligner_sw_col_1136> 0 <aligner_sw_col_1137> 0 <aligner_sw_col_1138> 0 <aligner_sw_col_1139> 0 
*/
//#include <limits>
//#include "aligner_sw.h"
//#include "aligner_sw_col.h"
//#include "search_globals.h"
//#include "scoring.h"
//#include "mask.h"
pair<int, int> SwColorCellMask::randOverallBacktrack(
RandomSource& rand,
bool& branch,
bool clear)
{
;
std::pair<int, int> ret;
if(ON(16155)){ret.second = -1;};
int i =
((oall_diag != 0) << 0) |
((oall_rfop != 0) << 1) |
((oall_rfex != 0) << 2) |
((oall_rdop != 0) << 3) |
((oall_rdex != 0) << 4);
int totChoices =
alts5[oall_diag] +
alts5[oall_rfop] +
alts5[oall_rfex] +
oall_rdop +
oall_rdex;
if(ON(16171)){branch = totChoices > 1;};
if(ON(16172)){ret.first = randFromMask(rand, i);};
;
if(ON(16174)){(static_cast<void> (0));};
if(ON(16180)) if(ret.first < 3) {
if(ON(16182)) if(ret.first == SW_BT_OALL_DIAG) {
if(ON(16183)){(static_cast<void> (0));};
if(ON(16184)){ret.second = randFromMask(rand, oall_diag);};
if(ON(16185)) if(clear) oall_diag &= ~(1 << ret.second);
} else if(ret.first == SW_BT_OALL_REF_OPEN) {
if(ON(16187)){(static_cast<void> (0));};
if(ON(16188)){ret.second = randFromMask(rand, oall_rfop);};
if(ON(16189)) if(clear) oall_rfop &= ~(1 << ret.second);
} else if(ret.first == SW_BT_OALL_REF_EXTEND) {
if(ON(16191)){(static_cast<void> (0));};
if(ON(16192)){ret.second = randFromMask(rand, oall_rfex);};
if(ON(16193)) if(clear) oall_rfex &= ~(1 << ret.second);
}
} else if(clear) {
if(ON(16196)) if(ret.first == SW_BT_OALL_READ_OPEN) {
if(ON(16197)){oall_rdop = 0;};
}
else if(ret.first == SW_BT_OALL_READ_EXTEND) {
if(ON(16200)){oall_rdex = 0;};
}
}
;
return ret;
}
pair<int, int> SwColorCellMask::randReadGapBacktrack(
RandomSource& rand,
bool& branch,
bool clear)
{
;
std::pair<int, int> ret;
if(ON(16222)){ret.second = -1;};
int i =
((rdgap_op != 0) << 0) |
((rdgap_ex != 0) << 1);
int totChoices = rdgap_op + rdgap_ex;
if(ON(16230)){branch = totChoices > 1;};
if(ON(16231)){ret.first = randFromMask(rand, i) + SW_BT_RDGAP_OPEN;};
if(ON(16232)){(static_cast<void> (0));};
if(ON(16234)) if(clear) {
if(ON(16235)) if(ret.first == SW_BT_RDGAP_OPEN) {
if(ON(16236)){rdgap_op = 0;};
} else {
if(ON(16238)){rdgap_ex = 0;};
}
}
;
return ret;
}
pair<int, int> SwColorCellMask::randRefGapBacktrack(
RandomSource& rand,
bool& branch,
bool clear)
{
;
std::pair<int, int> ret;
if(ON(16260)){ret.second = -1;};
int i =
((rfgap_op != 0) << 0) |
((rfgap_ex != 0) << 1);
int totChoices =
alts5[rfgap_op] +
alts5[rfgap_ex];
if(ON(16270)){branch = totChoices > 1;};
if(ON(16271)){ret.first = randFromMask(rand, i) + SW_BT_RFGAP_OPEN;};
if(ON(16272)){(static_cast<void> (0));};
if(ON(16274)) if(ret.first == SW_BT_RFGAP_OPEN) {
if(ON(16275)){(static_cast<void> (0));};
if(ON(16276)){ret.second = randFromMask(rand, rfgap_op);};
if(ON(16277)) if(clear) rfgap_op &= ~(1 << ret.second);
} else if(ret.first == SW_BT_RFGAP_EXTEND) {
if(ON(16279)){(static_cast<void> (0));};
if(ON(16280)){ret.second = randFromMask(rand, rfgap_ex);};
if(ON(16281)) if(clear) rfgap_ex &= ~(1 << ret.second);
}
;
return ret;
}
inline bool SwColorCell::finalize(TAlScore floorsc) {
;
for(int i = 0; i < 4; i++) {
bool aboveFloor = oallBest[i].score() >= floorsc;
if(ON(16294)) if(!mask[i].empty() && aboveFloor) {
if(ON(16295)){(static_cast<void> (0));};
;
if(ON(16297)){empty = false;};
break;
} else if(aboveFloor) {
if(ON(16303)){terminal[i] = true;};
}
}
return !empty;
}
bool SwAligner::backtrackColors(
TAlScore escore,
SwResult& res,
size_t& off,
size_t row,
size_t col,
int lastC,
RandomSource& rand)
{
typedef SwColorCell TCell;
ELList<TCell>& tab = ctab_;
;
;
;
if(ON(16350)){btcstack_.clear();};
if(ON(16351)){btcells_.clear();};
size_t tabcol = col - row;
;
int curC = lastC;
AlnScore score; score.score_ = 0;
if(ON(16356)){score.gaps_ = score.ns_ = 0;};
bool refExtend = false, readExtend = false;
size_t origCol = col;
size_t gaps = 0, readGaps = 0, refGaps = 0;
if(ON(16360)){res.alres.reset();};
EList<Edit>& ned = res.alres.ned();
EList<Edit>& ced = res.alres.ced();
if(ON(16364)){res.ndn = lastC;};
size_t trimEnd = dpRows() - row - 1;
size_t trimBeg = 0;
if(ON(16367)){(static_cast<void> (0));};
if(ON(16368)){(static_cast<void> (0));};
int ct = SW_BT_CELL_OALL;
;
while((int)row >= 0) {
if(ON(16372)){nbts_++;};
;
;
;
;
if(ON(16377)){tabcol = col - row;};
;
TCell& curc = tab[row][tabcol];
bool empty = curc.mask[curC].numPossible(ct) == 0;
;
;
if(ON(16384)) if(!curc.canMoveThrough(curC, ct)) {
if(ON(16385)) if(!btcstack_.empty()) {
if(ON(16387)){ned.resize(btcstack_.back().nedsz);};
if(ON(16388)){ced.resize(btcstack_.back().cedsz);};
if(ON(16389)){btcells_.resize(btcstack_.back().celsz);};
if(ON(16391)){row = btcstack_.back().row;};
if(ON(16392)){col = btcstack_.back().col;};
if(ON(16393)){gaps = btcstack_.back().gaps;};
if(ON(16394)){readGaps = btcstack_.back().readGaps;};
if(ON(16395)){refGaps = btcstack_.back().refGaps;};
if(ON(16396)){score = btcstack_.back().score;};
if(ON(16397)){curC = btcstack_.back().curC;};
if(ON(16398)){ct = btcstack_.back().ct;};
;
if(ON(16400)){btcstack_.pop_back();};
if(ON(16401)){(static_cast<void> (0));};
continue;
} else {
if(ON(16405)){res.reset();};
return false;
}
}
if(ON(16409)){(static_cast<void> (0));};
if(ON(16410)){(static_cast<void> (0));};
if(ON(16411)) if(row == 0) {
if(ON(16412)){btcells_.expand();};
if(ON(16413)){btcells_.back().first = row;};
if(ON(16414)){btcells_.back().second = tabcol;};
break;
}
if(ON(16417)) if(empty) {
;
if(ON(16420)){trimBeg = row;};
;
break;
}
bool branch = false;
pair<int, int> cur =
curc.mask[curC].randBacktrack(ct, rand, branch, true);
if(ON(16427)) if(branch) {
;
if(ON(16430)){btcstack_.expand();};
btcstack_.back().init(
ned.size(),
0,
ced.size(),
btcells_.size(),
row,
col,
curC,
gaps,
readGaps,
refGaps,
score,
ct
);
}
if(ON(16447)){btcells_.expand();};
if(ON(16448)){btcells_.back().first = row;};
if(ON(16449)){btcells_.back().second = tabcol;};
;
switch(cur.first) {
case SW_BT_OALL_DIAG: if(ON(16456)){ {}
;
if(ON(16458)){refExtend = readExtend = false;};
if(ON(16459)){; ;};
int refNmask = (int)rf_[rfi_+col];
;
int m = matchesEx(curC, refNmask);
;
if(ON(16465)){ct = SW_BT_CELL_OALL;};
if(ON(16466)) if(m != 1) {
Edit e((int)row, mask2dna[refNmask], "ACGTN"[curC], EDIT_TYPE_MM);
if(ON(16468)){(static_cast<void> (0));};
if(ON(16469)){(static_cast<void> (0));};
if(ON(16470)){ned.push_back(e);};
int pen = ((m == 0) ? sc_->snp : sc_->n(30));
if(ON(16472)){score.score_ -= pen;};
if(ON(16473)){(static_cast<void> (0));};
} else {
int64_t bonus = sc_->match(30);
if(ON(16476)){score.score_ += bonus;};
if(ON(16477)){(static_cast<void> (0));};
}
if(ON(16479)) if(m == -1) {
if(ON(16480)){score.ns_++;};
}
if(ON(16482)){row--; col--;};
;
if(ON(16484)){(static_cast<void> (0));};
int readC = (*rd_)[rdi_ + row];
int decC = dinuc2color[cur.second][curC];
;
if(ON(16489)) if(decC != readC) {
Edit e((int)row, "ACGT"[decC], "ACGTN"[readC], EDIT_TYPE_MM);
int pen = sc_->mm((int)(*rd_)[rdi_ + row], (int)(*qu_)[rdi_ + row] - 33);
if(ON(16492)){score.score_ -= pen;};
if(ON(16493)){(static_cast<void> (0));};
if(ON(16494)){(static_cast<void> (0));};
if(ON(16495)){(static_cast<void> (0));};
if(ON(16496)){ced.push_back(e);};
}
if(ON(16498)) if(readC > 3) {
if(ON(16499)){score.ns_++;};
}
;
if(ON(16502)){(static_cast<void> (0));};
if(ON(16503)){lastC = curC;};
if(ON(16504)){curC = cur.second;};
;
;
;
break;
}
case SW_BT_OALL_REF_OPEN: if(ON(16512)){}
case SW_BT_RFGAP_OPEN: if(ON(16513)){}
{
if(ON(16515)){refExtend = true; readExtend = false;};
;
Edit e((int)row, '-', "ACGTN"[curC], EDIT_TYPE_REF_GAP);
if(ON(16518)){(static_cast<void> (0));};
if(ON(16519)){(static_cast<void> (0));};
if(ON(16520)){ned.push_back(e);};
;
;
if(ON(16523)){row--;};
;
if(ON(16525)){ct = SW_BT_CELL_OALL;};
int decC = dinuc2color[cur.second][curC];
;
int rdC = (*rd_)[rdi_+row];
if(ON(16530)) if(decC != rdC) {
if(ON(16531)){score.score_ -= sc_->mm((int)(*rd_)[rdi_ + row], (int)(*qu_)[rdi_ + row] - 33);};
if(ON(16532)){(static_cast<void> (0));};
Edit e((int)row, "ACGT"[decC], "ACGTN"[rdC], EDIT_TYPE_MM);
if(ON(16534)){(static_cast<void> (0));};
if(ON(16535)){(static_cast<void> (0));};
if(ON(16536)){ced.push_back(e);};
}
if(ON(16538)) if(rdC > 3) {
if(ON(16539)){score.ns_++;};
}
if(ON(16541)){score.score_ -= sc_->refGapOpen();};
if(ON(16542)){(static_cast<void> (0));};
if(ON(16543)){gaps++; refGaps++;};
;
;
;
;
if(ON(16548)){lastC = curC;};
if(ON(16549)){curC = cur.second;};
;
;
;
break;
}
case SW_BT_OALL_REF_EXTEND: if(ON(16557)){}
case SW_BT_RFGAP_EXTEND: if(ON(16558)){}
{
if(ON(16560)){refExtend = true; readExtend = false;};
;
Edit e((int)row, '-', "ACGTN"[curC], EDIT_TYPE_REF_GAP);
if(ON(16563)){(static_cast<void> (0));};
if(ON(16564)){(static_cast<void> (0));};
if(ON(16565)){ned.push_back(e);};
;
;
if(ON(16568)){row--;};
;
if(ON(16570)){ct = SW_BT_CELL_RFGAP;};
int decC = dinuc2color[cur.second][curC];
;
int rdC = (*rd_)[rdi_+row];
if(ON(16575)) if(decC != rdC) {
if(ON(16576)){score.score_ -= sc_->mm((int)(*rd_)[rdi_ + row], (int)(*qu_)[rdi_ + row] - 33);};
if(ON(16577)){(static_cast<void> (0));};
Edit e((int)row, "ACGT"[decC], "ACGTN"[rdC], EDIT_TYPE_MM);
if(ON(16579)){(static_cast<void> (0));};
if(ON(16580)){(static_cast<void> (0));};
if(ON(16581)){ced.push_back(e);};
}
if(ON(16583)) if(rdC > 3) {
if(ON(16584)){score.ns_++;};
}
if(ON(16586)){score.score_ -= sc_->refGapExtend();};
if(ON(16587)){(static_cast<void> (0));};
if(ON(16588)){gaps++; refGaps++;};
;
;
;
;
if(ON(16593)){lastC = curC;};
if(ON(16594)){curC = cur.second;};
;
;
;
break;
}
case SW_BT_OALL_READ_OPEN: if(ON(16600)){}
case SW_BT_RDGAP_OPEN: if(ON(16601)){}
{
if(ON(16603)){refExtend = false; readExtend = true;};
;
Edit e((int)row+1, "ACGTN"[firsts5[(int)rf_[rfi_+col]]], '-', EDIT_TYPE_READ_GAP);
if(ON(16606)){(static_cast<void> (0));};
if(ON(16607)){(static_cast<void> (0));};
if(ON(16608)){ned.push_back(e);};
;
;
if(ON(16611)){col--;};
;
if(ON(16613)){ct = SW_BT_CELL_OALL;};
if(ON(16614)){score.score_ -= sc_->readGapOpen();};
if(ON(16615)){(static_cast<void> (0));};
if(ON(16616)){gaps++; readGaps++;};
;
;
;
;
if(ON(16621)){lastC = curC;};
;
;
break;
}
case SW_BT_OALL_READ_EXTEND: if(ON(16626)){}
case SW_BT_RDGAP_EXTEND: if(ON(16627)){}
{
if(ON(16629)){refExtend = false; readExtend = true;};
;
Edit e((int)row+1, "ACGTN"[firsts5[(int)rf_[rfi_+col]]], '-', EDIT_TYPE_READ_GAP);
if(ON(16632)){(static_cast<void> (0));};
if(ON(16633)){(static_cast<void> (0));};
if(ON(16634)){ned.push_back(e);};
;
;
if(ON(16637)){col--;};
;
if(ON(16639)){ct = SW_BT_CELL_RDGAP;};
if(ON(16640)){score.score_ -= sc_->readGapExtend();};
if(ON(16641)){(static_cast<void> (0));};
if(ON(16642)){gaps++; readGaps++;};
;
;
;
;
if(ON(16647)){lastC = curC;};
;
;
break;
}
if(ON(16652)){default: throw 1;};
}
}
;
;
;
for(size_t i = 0; i < btcells_.size(); i++) {
size_t rw = btcells_[i].first;
size_t cl = btcells_[i].second;
if(ON(16663)){(static_cast<void> (0));};
if(ON(16664)){tab[rw][cl].setReportedThrough();};
}
;
int refNmask = (int)rf_[rfi_+col];
;
int m = matchesEx(curC, refNmask);
int pen = 0;
if(ON(16671)) if(m != 1) {
Edit e((int)row, mask2dna[refNmask], "ACGTN"[curC], EDIT_TYPE_MM);
if(ON(16673)){(static_cast<void> (0));};
if(ON(16674)){(static_cast<void> (0));};
if(ON(16675)){ned.push_back(e);};
if(ON(16676)){pen = ((m == 0) ? sc_->snp : sc_->n(30));};
if(ON(16677)){score.score_ -= pen;};
if(ON(16678)){(static_cast<void> (0));};
}
if(ON(16681)) if(m == -1) {
if(ON(16682)){score.ns_++;};
}
;
if(ON(16685)){res.nup = curC;};
if(ON(16686)){res.reverse();};
if(ON(16687)){(static_cast<void> (0));};
;
;
if(ON(16718)){off = (col - row);};
if(ON(16719)){score.gaps_ = gaps;};
if(ON(16720)){res.alres.setScore(score);};
res.alres.setShape(
refidx_,
off + rfi_ + refoff_,
fw_,
rdf_ - rdi_,
color_,
true,
0,
0,
false,
fw_ ? trimBeg : trimEnd,
fw_ ? trimEnd : trimBeg);
size_t refns = 0;
for(size_t i = col; i <= origCol; i++) {
if(ON(16735)) if((int)rf_[rfi_+i] > 15) {
if(ON(16736)){refns++;};
}
}
if(ON(16739)){res.alres.setRefNs(refns);};
if(ON(16740)){(static_cast<void> (0));};
return true;
}
inline void SwAligner::updateColorHoriz(
const SwColorCell& lc,
SwColorCell& dstc,
int rfm)
{
if(ON(16767)){(static_cast<void> (0));};
if(ON(16768)) if(lc.empty) return;
;
for(int to = 0; to < 4; to++) {
AlnScore leftOallBest = lc.oallBest[to];
AlnScore leftRdgapBest = lc.rdgapBest[to];
AlnScore& myOallBest = dstc.oallBest[to];
AlnScore& myRdgapBest = dstc.rdgapBest[to];
SwColorCellMask& myMask = dstc.mask[to];
if(ON(16776)){(static_cast<void> (0));};
if(ON(16777)){(static_cast<void> (0));};
;
if(ON(16779)) if(!((leftOallBest).score_ > std::numeric_limits<TAlScore>::min())) {
if(ON(16780)){(static_cast<void> (0));};
return;
}
;
;
AlnScore ex = leftRdgapBest - sc_->readGapExtend();
if(ON(16787)) if(ex.score_ >= floorsc_) {
if(ON(16788)) if(ex >= myOallBest) {
if(ON(16789)) if(ex > myOallBest) {
if(ON(16790)){myMask.clearOverallMask();};
if(ON(16791)){myOallBest = ex;};
}
if(ON(16793)){myMask.oall_rdex = 1;};
}
if(ON(16795)) if(ex >= myRdgapBest) {
if(ON(16796)) if(ex > myRdgapBest) {
if(ON(16797)){myMask.clearReadGapMask();};
if(ON(16798)){myRdgapBest = ex;};
}
if(ON(16800)){myMask.rdgap_ex = 1;};
}
}
if(ON(16804)){ex = leftOallBest - sc_->readGapOpen();};
if(ON(16805)) if(ex.score_ >= floorsc_) {
if(ON(16806)) if(ex >= myOallBest) {
if(ON(16807)) if(ex > myOallBest) {
if(ON(16808)){myMask.clearOverallMask();};
if(ON(16809)){myOallBest = ex;};
}
if(ON(16811)){myMask.oall_rdop = 1;};
}
if(ON(16813)) if(ex >= myRdgapBest) {
if(ON(16814)) if(ex > myRdgapBest) {
if(ON(16815)){myMask.clearReadGapMask();};
if(ON(16816)){myRdgapBest = ex;};
}
if(ON(16818)){myMask.rdgap_op = 1;};
}
}
}
}
inline void SwAligner::updateColorVert(
const SwColorCell& uc,
SwColorCell& dstc,
int c,
int penmm)
{
if(ON(16834)){(static_cast<void> (0));};
if(ON(16835)) if(uc.empty) return;
for(int to = 0; to < 4; to++) {
AlnScore fromOall[] = {
uc.oallBest[0], uc.oallBest[1],
uc.oallBest[2], uc.oallBest[3] };
AlnScore fromRfgap[] = {
uc.rfgapBest[0], uc.rfgapBest[1],
uc.rfgapBest[2], uc.rfgapBest[3] };
const int goodfrom = nuccol2nuc[to][c];
if(ON(16849)) if(goodfrom < 4) {
if(ON(16850)) if(fromOall [goodfrom].valid()) fromOall [goodfrom].score_ += penmm;
if(ON(16851)) if(fromRfgap[goodfrom].valid()) fromRfgap[goodfrom].score_ += penmm;
}
for(int fr = 0; fr < 4; fr++) {
AlnScore upOallBest = fromOall[fr] - penmm;
AlnScore upRfgapBest = fromRfgap[fr] - penmm;
AlnScore& myOallBest = dstc.oallBest[to];
AlnScore& myRfgapBest = dstc.rfgapBest[to];
SwColorCellMask& myMask = dstc.mask[to];
if(ON(16859)){(static_cast<void> (0));};
if(ON(16860)){(static_cast<void> (0));};
;
if(ON(16862)) if(!((upOallBest).score_ > std::numeric_limits<TAlScore>::min())) {
if(ON(16863)){(static_cast<void> (0));};
return;
}
;
;
AlnScore ex = upRfgapBest - sc_->refGapExtend();
if(ON(16870)) if(ex.score_ >= floorsc_) {
if(ON(16871)) if(ex >= myOallBest) {
if(ON(16872)) if(ex > myOallBest) {
if(ON(16873)){myMask.clearOverallMask();};
if(ON(16874)){myOallBest = ex;};
}
if(ON(16876)){myMask.oall_rfex |= (1 << fr);};
}
if(ON(16878)) if(ex >= myRfgapBest) {
if(ON(16879)) if(ex > myRfgapBest) {
if(ON(16880)){myMask.clearRefGapMask();};
if(ON(16881)){myRfgapBest = ex;};
}
if(ON(16883)){myMask.rfgap_ex |= (1 << fr);};
}
}
if(ON(16887)){ex = upOallBest - sc_->refGapOpen();};
if(ON(16888)) if(ex.score_ >= floorsc_) {
if(ON(16889)) if(ex >= myOallBest) {
if(ON(16890)) if(ex > myOallBest) {
if(ON(16891)){myMask.clearOverallMask();};
if(ON(16892)){myOallBest = ex;};
}
if(ON(16894)){myMask.oall_rfop |= (1 << fr);};
}
if(ON(16896)) if(ex >= myRfgapBest) {
if(ON(16897)) if(ex > myRfgapBest) {
if(ON(16898)){myMask.clearRefGapMask();};
if(ON(16899)){myRfgapBest = ex;};
}
if(ON(16901)){myMask.rfgap_op |= (1 << fr);};
}
}
}
}
}
inline void SwAligner::updateColorDiag(
const SwColorCell& uc,
SwColorCell& dstc,
int refMask,
int c,
int penmm,
bool& improved)
{
if(ON(16920)){(static_cast<void> (0));};
if(ON(16921)) if(uc.empty) return;
;
if(ON(16925)){improved = true;};
for(int to = 0; to < 4; to++) {
TAlScore add =
(matches(to, refMask) ?
sc_->match(30) :
-((refMask > 15) ? sc_->n(30) : sc_->snp));
AlnScore fromOall[] = {
uc.oallBest[0], uc.oallBest[1],
uc.oallBest[2], uc.oallBest[3] };
const int goodfrom = nuccol2nuc[to][c];
if(ON(16937)) if(goodfrom < 4) {
if(ON(16938)) if(fromOall[goodfrom].valid()) {
if(ON(16940)){fromOall[goodfrom].score_ += penmm;};
}
}
for(int fr = 0; fr < 4; fr++) {
AlnScore dcOallBest = fromOall[fr] - penmm;
AlnScore& myOallBest = dstc.oallBest[to];
SwColorCellMask& myMask = dstc.mask[to];
if(ON(16947)){(static_cast<void> (0));};
if(ON(16948)) if(!((dcOallBest).score_ > std::numeric_limits<TAlScore>::min())) {
continue;
}
;
AlnScore ex = dcOallBest + (int)add;
if(ON(16953)) if(ex.score_ >= floorsc_ && ex >= myOallBest) {
if(ON(16954)) if(ex > myOallBest) {
if(ON(16955)){myOallBest = ex;};
if(ON(16956)){myMask.clear();};
}
if(ON(16958)){myMask.oall_diag |= (1 << fr);};
}
}
}
}
TAlScore SwAligner::alignColors() {
typedef SwColorCell TCell;
;
;
;
;
;
;
if(ON(17041)){(static_cast<void> (0));};
ELList<TCell>& tab = ctab_;
if(ON(17051)){tab.resize(1);};
const size_t wlo = 0;
const size_t whi = (int)(width_ - 1);
if(ON(17054)){tab[0].resize(whi-wlo+1);};
bool validInRow = !sc_->monotone;;
TAlScore best = std::numeric_limits<TAlScore>::min();
for(size_t col = 0; col <= whi; col++) {
TCell& curc = tab[0][col];
if(ON(17064)){curc.clear();};
size_t fromend = whi - col;
int rfm = rf_[rfi_+col];
bool canStart = true;
bool improved = false;
if(ON(17074)) if(canStart) {
for(int to = 0; to < 4; to++) {
if(ON(17076)){curc.oallBest[to].invalidate();};
if(ON(17077)){curc.rdgapBest[to].invalidate();};
if(ON(17078)){curc.rfgapBest[to].invalidate();};
int m = matchesEx(to, rfm);
if(ON(17080)) if(m == 1) {
;
if(ON(17084)){curc.oallBest[to].gaps_ = 0;};
if(ON(17085)){curc.oallBest[to].ns_ = 0;};
if(ON(17086)){curc.oallBest[to].score_ = 0;};
if(ON(17087)){curc.mask[to].oall_diag = 0xf;};
if(ON(17088)){improved = true;};
} else if(m == 0 && sc_->snp <= -minsc_) {
if(ON(17092)){curc.oallBest[to].gaps_ = 0;};
if(ON(17093)){curc.oallBest[to].ns_ = 0;};
if(ON(17094)){curc.oallBest[to].score_ = -sc_->snp;};
if(ON(17095)){curc.mask[to].oall_diag = 0xf;};
} else if(m == -1) {
if(ON(17098)){curc.oallBest[to].gaps_ = 0;};
if(ON(17099)){curc.oallBest[to].ns_ = 1;};
if(ON(17100)){curc.oallBest[to].score_ = -sc_->n(30);};
if(ON(17101)){curc.mask[to].oall_diag = 0xf;};
} else {
}
}
}
if(ON(17108)) if(sc_->gapbar < 1 && col > 0) {
if(ON(17109)){updateColorHoriz(tab[0][col-1], curc, rfm);};
if(ON(17110)){ncups_++;};
}
if(ON(17112)){{ ; (static_cast<void> (0)); if(tab[0][col].finalize(floorsc_)) { { if(fromend < solwidth_) { size_t widcol = solwidth_ - fromend - 1; if(en_ == __null || (*en_)[widcol]) { for(int I = 0; I < 4; I++) { if(tab[0][col].oallBest[I].score() >= minsc_) { const bool local = !sc_->monotone; if(!local || improved) { if((int64_t)0 >= solrowlo_) { if(tab[0][col].oallBest[I].score() > best) { best = tab[0][col].oallBest[I].score(); } tab[0][col].backtraceCandidate = true; if(0 > 0) tab[0 -1][col].backtraceCandidate = false; (static_cast<void> (0)); } } } } } } }; validInRow = true; } (static_cast<void> (0)); };};
}
if(ON(17114)){nrowups_++;};
if(ON(17115)) if(!validInRow) {
if(ON(17116)){nrowskips_ += (rdf_ - rdi_);};
return std::numeric_limits<TAlScore>::min();
}
for(size_t row = 1; row <= rdf_ - rdi_; row++) {
if(ON(17126)){nrowups_++;};
if(ON(17127)){tab.expand();};
size_t fromend = whi - 0;
bool onlyDiagInto =
(row+1 <= (size_t)sc_->gapbar ||
rdf_ - rdi_ - row <= (size_t)sc_->gapbar);
if(ON(17132)){tab.back().resize(whi-wlo+1);};
;
;
;
int c = (*rd_)[row-1];
int q = sc_->mm((int)(*rd_)[rdi_ + row-1], (int)(*qu_)[rdi_ + row-1] - 33);
;
const int mmpen = ((c > 3) ? sc_->n(30) : sc_->mm(q));
if(ON(17140)){validInRow = !sc_->monotone;;};
;
size_t col = wlo;
TCell& cur = tab[row][0];
if(ON(17149)){cur.clear();};
bool improved = false;
if(ON(17151)) if(!tab[row-1][0].empty) {
const size_t fullcol = col + row;
updateColorDiag(
tab[row-1][0],
cur,
rf_[rfi_ + fullcol],
c,
mmpen,
improved);
}
if(ON(17161)) if(!onlyDiagInto && col < whi && !tab[row-1][1].empty) {
updateColorVert(
tab[row-1][1],
cur,
c,
mmpen);
}
if(ON(17168)){ncups_++;};
if(ON(17170)){{ ; (static_cast<void> (0)); if(tab[row][col].finalize(floorsc_)) { { if(fromend < solwidth_) { size_t widcol = solwidth_ - fromend - 1; if(en_ == __null || (*en_)[widcol]) { for(int I = 0; I < 4; I++) { if(tab[row][col].oallBest[I].score() >= minsc_) { const bool local = !sc_->monotone; if(!local || improved) { if((int64_t)row >= solrowlo_) { if(tab[row][col].oallBest[I].score() > best) { best = tab[row][col].oallBest[I].score(); } tab[row][col].backtraceCandidate = true; if(row > 0) tab[row-1][col].backtraceCandidate = false; (static_cast<void> (0)); } } } } } } }; validInRow = true; } (static_cast<void> (0)); };};
for(col = wlo+1; col < whi; col++) {
const size_t fullcol = col + row;
int r = rf_[rfi_ + fullcol];
size_t fromend = whi - col;
TCell& cur = tab[row][col-wlo];
if(ON(17177)){cur.clear();};
TCell& dg = tab[row-1][col-wlo];
if(ON(17179)){improved = false;};
updateColorDiag(
dg,
cur,
r,
c,
mmpen,
improved);
if(ON(17192)) if(!onlyDiagInto) {
TCell& up = tab[row-1][col-wlo+1];
updateColorVert(
up,
cur,
c,
mmpen);
TCell& lf = tab[row][col-wlo-1];
updateColorHoriz(
lf,
cur,
r);
}
if(ON(17206)){ncups_++;};
if(ON(17208)){{ ; (static_cast<void> (0)); if(tab[row][col].finalize(floorsc_)) { { if(fromend < solwidth_) { size_t widcol = solwidth_ - fromend - 1; if(en_ == __null || (*en_)[widcol]) { for(int I = 0; I < 4; I++) { if(tab[row][col].oallBest[I].score() >= minsc_) { const bool local = !sc_->monotone; if(!local || improved) { if((int64_t)row >= solrowlo_) { if(tab[row][col].oallBest[I].score() > best) { best = tab[row][col].oallBest[I].score(); } tab[row][col].backtraceCandidate = true; if(row > 0) tab[row-1][col].backtraceCandidate = false; (static_cast<void> (0)); } } } } } } }; validInRow = true; } (static_cast<void> (0)); };};
}
if(ON(17215)) if(whi > wlo) {
size_t fromend = 0;
if(ON(17217)){col = whi;};
TCell& cur = tab[row][col-wlo];
if(ON(17219)){cur.clear();};
const size_t fullcol = col + row;
const int r = rf_[rfi_ + fullcol];
TCell& dg = tab[row-1][col-wlo];
if(ON(17223)){improved = false;};
if(ON(17224)) if(!dg.empty) {
updateColorDiag(
dg,
cur,
r,
c,
mmpen,
improved);
}
TCell& lf = tab[row][col-wlo-1];
if(ON(17234)) if(!onlyDiagInto && !lf.empty) {
updateColorHoriz(
lf,
cur,
r);
}
if(ON(17240)){ncups_++;};
if(ON(17242)){{ ; (static_cast<void> (0)); if(tab[row][col].finalize(floorsc_)) { { if(fromend < solwidth_) { size_t widcol = solwidth_ - fromend - 1; if(en_ == __null || (*en_)[widcol]) { for(int I = 0; I < 4; I++) { if(tab[row][col].oallBest[I].score() >= minsc_) { const bool local = !sc_->monotone; if(!local || improved) { if((int64_t)row >= solrowlo_) { if(tab[row][col].oallBest[I].score() > best) { best = tab[row][col].oallBest[I].score(); } tab[row][col].backtraceCandidate = true; if(row > 0) tab[row-1][col].backtraceCandidate = false; (static_cast<void> (0)); } } } } } } }; validInRow = true; } (static_cast<void> (0)); };};
}
if(ON(17244)) if(!validInRow) {
;
if(ON(17246)){nrowskips_ += (rdf_ - rdi_ - row);};
return std::numeric_limits<TAlScore>::min();
}
}
;
return best;
}
