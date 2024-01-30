all :
	@cd manda && make
	@echo "minitalk ready ✅"

bonus :
	@cd bonuus && make
	@echo "minitalk bonus ready ✅"

clean :
	@cd manda && make clean
	@cd bonuus && make clean
	@echo "all clean"

fclean : clean
	@cd manda && make fclean
	@cd bonuus && make fclean

re : fclean all

re_bonus : fclean bonus

.PHONY: clean fclean bonus all