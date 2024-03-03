all:
	@echo "CC homer.c"
	@gcc homer.c -o homer -std=c11 -Wall -pedantic -Werror 
install: 
	@cp homer ~/.local/bin/homer
	@cp -r .poem ~/.poem
	@echo "homer installed at ~/.local/bin"
