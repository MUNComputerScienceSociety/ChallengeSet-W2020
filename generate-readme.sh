#!/usr/bin/env sh

list_contribs() {
  for week in $( find . -maxdepth 2 -name "week-*" )
  do
    for contrib in $( find "$week" -mindepth 1 -maxdepth 1 ! -iname "*.md" ! -iname "test-samples" )
    do
      basename "$contrib"
    done
  done | sort | uniq
}

print_contribs() {
  for contrib in $( list_contribs )
  do
    printf -- "- $contrib, "
    for contribution in $( find . -mindepth 2 -maxdepth 2 -iname "$contrib" ! -iname "*.md" ! -iname "test-samples" | sort )
    do
      printf "[$(basename "$(dirname "$contribution")")]($contribution) "
    done
    printf "\n"
  done
}

print_weeks() {
  for readme in $( find . -mindepth 2 -maxdepth 2 -iname "README.md" | sort )
  do
    printf -- "- [$(cat "$readme" | head -n 1 | sed 's/# *//')](./$(basename "$(dirname "$readme")"))\n"
  done
}

printf "# MUNCS ChallengeSet - Winter 2020\n\na _set_ of _challenges_\n\n"
print_weeks
printf "\n## Contributors:\n\n"
print_contribs
