#!/bin/bash

# clear.sh help
genn_help () {
    echo "clear.sh script usage:"
    echo "clear.sh model"
}

# handle script errors
genn_error () { # $1=line, $2=code, $3=message
    echo "fullrun.sh:$1: error $2: $3"
    rm $MODEL_PATH
    exit "$2"
}
trap 'genn_error $LINENO 50 "command failure"' ERR

# parse command options
while [[ -n "${!OPTIND}" ]]; do
    if [[ $OPTIND > $# ]]; then break; fi
    MODEL="${!OPTIND}"
    let OPTIND++
done

if [[ -z "$MODEL" ]]; then
    genn_error $LINENO 2 "no model file given"
fi

rm -rf $MODEL/${MODEL}_CODE
rm $MODEL/generator
rm $MODEL/generator.d
rm $MODEL/Makefile
rm $MODEL/$MODEL