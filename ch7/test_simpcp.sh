#!/bin/bash
# ch7/test_simpcp.sh
# Simple wrapper script over the 'simpcp?.c' utils to test-run them.
name=$(basename $0)
SRC=srcfile
DEST=destfile

[ $# -ne 2 ] && {
  echo "Usage: ${name} PUT(program-under-test) src-filesize-KB
 Eg. ${name} ./simpcp2 21"
  exit 1
}

PUT=$1
[ ! -f ${PUT} ] && {
  echo "${name}: program-under-test \"${PUT}\" not built or missing?"
  exit 1
}
SRC_SIZE_BLK_KB=$2        # srcfile size will be this many kilobytes
rm -f ${SRC} ${DEST}

# Create the source file
dd if=/dev/urandom of=${SRC} bs=1k count=${SRC_SIZE_BLK_KB} 2>/dev/null

echo "${PUT} ${SRC} ${DEST} 1"
${PUT} ${SRC} ${DEST} 1

echo
ls -l ${SRC} ${DEST}
echo "Diff-ing them now ..."
diff ${SRC} ${DEST}
echo "Done."
exit 0
