SoAL Disassembly
----------------

### SkiesOfArcadiaLegends

The new, fresh copy of the disassembly that AdituV is working on.
As of 2020-05-02, the known functions and values from the old copy have not been carried over.
Current progress: mapping SDK functions

### SOAL_oldver

The original copy of the disassembly.  Was created with incorrect small data area pointers,
so parts of the annotation are wrong.  Needs verification and for the known good parts to
be merged into SkiesOfArcadiaLegends

### gcn_sdk.gdt

Contains type definitions used in gamecube SDK functions.  It does not contain the SDK itself
or any implementations.

### metroworks_clib.gdt

Contains type definitions used in the C standard library headers from a compiler known to
have been used for gamecube development.