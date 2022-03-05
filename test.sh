#!/bin/zsh
# test script for canons a 2, fifth below (type 0) or fifth above (type 1)
# ./test.sh <type: 0 or 1> <number of notes: 1, ...> <number of tests: 1,...>
#
d=$(date "+%s") 
mkdir test_series/$d
for ((i=1;i<=$3;i++)); do
    ./sketch $1 $2
    lilypond.sh transcription.ly
    c=$(printf "%03d" $i)
    pdf="ca2.$d.$1$2.$c.pdf"
    lyl="ca2.$d.$1$2.$c.ly"
    mid="ca2.$d.$1$2.$c.midi"
    cp transcription.pdf test_series/$d/$pdf
    cp transcription.ly test_series/$d/$lyl
    cp transcription.midi test_series/$d/$mid
    echo $d
done

pdfunite $(ls test_series/$d/*.pdf | sort -n) test_series/$d/output.pdf