
/******************************************************************************
 *
 *  This file is part of canu, a software program that assembles whole-genome
 *  sequencing reads into contigs.
 *
 *  This software is based on:
 *    'Celera Assembler' (http://wgs-assembler.sourceforge.net)
 *    the 'kmer package' (http://kmer.sourceforge.net)
 *  both originally distributed by Applera Corporation under the GNU General
 *  Public License, version 2.
 *
 *  Canu branched from Celera Assembler at its revision 4587.
 *  Canu branched from the kmer project at its revision 1994.
 *
 *  Modifications by:
 *
 *    Brian P. Walenz on 2014-DEC-08
 *      are Copyright 2014 Battelle National Biodefense Institute, and
 *      are subject to the BSD 3-Clause License
 *
 *  File 'README.licenses' in the root directory of this distribution contains
 *  full conditions and disclaimers for each license.
 */

#ifndef SEQFACTORY_H
#define SEQFACTORY_H

#include "seqFile.H"

class seqFactory {
protected:
  seqFactory();
  ~seqFactory();

public:
  static seqFactory *instance(void) {
    if (me == 0L)
      me = new seqFactory;
    return(me);
  };

  void           registerFile(seqFile   *f);
  seqFile       *openFile(const char *name);
private:
  static seqFactory  *me;

  uint32         _filesNum;
  uint32         _filesMax;
  seqFile      **_files;
};


#define openSeqFile(S)    seqFactory::instance()->openFile((S))


#endif  //  SEQFACTORY_H
