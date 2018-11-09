#!/bin/bash

REMOVE_DIRECTORIES="bin/x11_game_engine_test build/ lib/ include/x11_game_engine/"

function main {
	for directory in ${REMOVE_DIRECTORIES}; do
		rm -rf $directory
	done
}

main "$@"