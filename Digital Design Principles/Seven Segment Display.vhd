library ieee;
use ieee.std_logic_1164.all;

entity ltplab7 is 
port( 
INP : in std_logic_vector(3 downto 0);
HEX : out std_logic_vector(0 to 6)
);
end ltplab7;

architecture Sevenseg of ltplab7 is
begin
process(INP)
begin
  case INP is
	  when "0000" => HEX <= "0000001";
	  when "0001" => HEX <= "1001111";
	  when "0010" => HEX <= "0010010";
	  when "0011" => HEX <= "0000110";
	  when "0100" => HEX <= "1001100";
	  when "0101" => HEX <= "0100100";
	  when "0110" => HEX <= "0100000";
	  when "0111" => HEX <= "0001111";
	  when "1000" => HEX <= "0000000";
	  when "1001" => HEX <= "0001100";
	  when "1010" => HEX <= "0001000";
	  when "1011" => HEX <= "1100000";
	  when "1100" => HEX <= "0110001";
	  when "1101" => HEX <= "1000010";
	  when "1110" => HEX <= "0110000";
	  when "1111" => HEX <= "0111000";
	  when others => HEX <= "XXXXXXX";
  end case;
end process;
end Sevenseg;
	