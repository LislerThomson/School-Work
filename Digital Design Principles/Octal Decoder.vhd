library ieee;
use ieee.std_logic_1164.all;

entity ltplab4 is
port(X:in std_logic_vector(2 downto 0);
Y:out std_logic_vector(7 downto 0)
);
end ltplab4;

architecture OCTAL of ltplab4 is
begin
	Y <= "00000001" when X = "000" else
		  "00000010" when X = "001" else
		  "00000100" when X = "010" else
		  "00001000" when X = "011" else
		  "00010000" when X = "100" else
		  "00100000" when X = "101" else
		  "01000000" when X = "110" else
		  "10000000" when X = "111";
end OCTAL;
	