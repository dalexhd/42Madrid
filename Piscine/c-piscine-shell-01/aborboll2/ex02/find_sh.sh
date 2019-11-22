#!/bin/bash
find . -type f -name "*.sh" -exec basename \{} .sh \;  | sed 's/[.]sh//g' | sed 's/[./]//g'
