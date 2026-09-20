#!/usr/bin/env bash

grey=$'\033[0;90m'
green=$'\033[0;32m'
reset=$'\033[0m'

log() {
    printf '%s%s%s\n' "$grey" "$*" "$reset"
}

usage() {
    log "Usage: $0 -n <problem_number>"
}

while getopts ":n:h" opt; do
    case "$opt" in
        n)
            printf -v number "%03d" "$OPTARG"

            found=0
            overall_status=0

            for source in "./${number}."*.c; do
                [[ -e "$source" ]] || continue
                found=1

                executable="${source%.c}"

                log "Compiling $source..."
                gcc "$source" -o "$executable"

                if [[ $? -ne 0 ]]; then
                    log "Compilation failed."
                    overall_status=1
                    continue
                fi

                log "Executing $executable..."

                "$executable" 2>&1 |
                    sed "s/^/${green}/; s/\$/${reset}/"

                status=${PIPESTATUS[0]}

                log "Removing $executable..."
                rm -f "$executable"

                if [[ $status -ne 0 ]]; then
                    overall_status=1
                fi
            done

            if [[ "$found" -eq 0 ]]; then
                log "Error: no matching C source file found for ${number}"
                exit 1
            fi

            exit "$overall_status"
            ;;

        h)
            usage
            exit 0
            ;;

        \?)
            log "Invalid option: -$OPTARG"
            usage
            exit 1
            ;;

        :)
            log "Option -$OPTARG requires an argument."
            exit 1
            ;;
    esac
done
