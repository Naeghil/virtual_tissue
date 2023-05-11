#!/bin/bash

# fullrun.sh help
genn_help () {
    echo "fullrun.sh script usage:"
    echo "fullrun.sh [hbf] model"
    echo "-h            shows this help message"
    echo "-b            rebuild model code; only user code is built otherwise"
    echo "-f            force model to be rebuilt even if GeNN doesn't think it's required, only if rebuild"
}

# handle script errors
genn_error () { # $1=line, $2=code, $3=message
    echo "fullrun.sh:$1: error $2: $3"
    exit "$2"
}
trap 'genn_error $LINENO 50 "command failure"' ERR

# parse command options
while [[ -n "${!OPTIND}" ]]; do
    while getopts "hbf" option; do
    case $option in
        b) REBUILD=1;;
        f) FORCE_REBUILD=1;;
        h) genn_help; exit;;
        ?) genn_help; exit;;
    esac
    done
    if [[ $OPTIND > $# ]]; then break; fi
    MODEL="${!OPTIND}"
    let OPTIND++
done

if [[ -z "$MODEL" ]]; then
    genn_error $LINENO 2 "no model file given"
fi

cd ./$MODEL

if [ $REBUILD ]
    then
    if [ $FORCE_REBUILD ]
    then
        genn-buildmodel.sh -f definition.cc
    else 
        genn-buildmodel.sh definition.cc
    fi
fi

genn-create-user-project.sh $MODEL user.cc
make

./$MODEL

cd ..

