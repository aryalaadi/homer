all:
	@echo "CC homer.c"
	@gcc homer.c -o homer -std=c11 -Wall -pedantic -Werror 
install: 
	@cp homer /home/kalekale/.local/bin/homer
	@cp -r .poem /home/kalekale/.poem
	@echo "homer installed at ~/.local/bin"
