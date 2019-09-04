library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.numeric_std.ALL;

entity ltplab5 is
port (sw : in std_logic_vector(7 downto 0);
led : out std_logic_vector(2 downto 0)
);
end ltplab5;

architecture Compare of ltplab5 is 
signal A : std_logic_vector(3 downto 0);
signal B : std_logic_vector(3 downto 0);
signal GT : std_logic;
signal EQ : std_logic;
signal LT : std_logic;

begin
	A(3 downto 0) <= sw(3 downto 0);
	B(3 downto 0) <= sw(7 downto 4);
	process (A,B)
	begin 
		if (unsigned(A) = unsigned(B)) then
			EQ <= '1';
		else
			EQ <= '0';
		end if;
		if (unsigned(A) > unsigned(B))  then
			GT <= '1';
		else
			GT <= '0';
		end if;
		if (unsigned(A) < unsigned(B)) then
			LT <= '1';
		else
			LT <= '0';
		end if;	
		end process;
	led(0) <= LT;
	led(1) <= EQ;
	led(2) <= GT;
end Compare;
