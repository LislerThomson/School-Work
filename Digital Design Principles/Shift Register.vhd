library ieee;
use ieee.std_logic_1164.all;

entity ltplab8 is
port(
sw: in std_logic_vector(7 downto 0);
led: out std_logic_vector(3 downto 0);
clk: in std_logic
);
end ltplab8;

architecture ShiftRegister of ltplab8 is

signal R: std_logic_vector(3 downto 0);
signal S: std_logic_vector(1 downto 0);

begin

S <= sw(7 downto 6);
led <= R;

process(clk)

begin
		if (rising_edge(clk)) then
			case S is
				when "00" =>
					NULL;
				when "01" =>
					R <= (R(2 downto 0) & sw(0));
				when "10" =>
					R <= (sw(5) & R(3 downto 1));
				when "11" =>
					R <= sw(4 downto 1);
				when others =>
					NULL;
			end case;
		end if;
end process;

end ShiftRegister;