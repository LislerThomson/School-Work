library ieee;
use ieee.std_logic_1164.all;

entity ltplab6_1 is
port(sw:in std_logic_vector(7 downto 0);
led:out std_logic_vector(7 downto 0));
end ltplab6_1;

architecture half_adder of ltplab6_1 is

	signal A :std_logic_vector(3 downto 0);
	signal B :std_logic_vector(7 downto 4);
	signal Sum:std_logic_vector(3 downto 0);
	signal Carry:std_logic_vector(7 downto 4);

	begin
	
		A(3 downto 0) <= sw(3 downto 0);
		B(7 downto 4) <= sw(7 downto 4);
		
		Sum(0) <= A(0) XOR B(4);
		Carry(4) <= A(0) AND B(4);
		
		Sum(1) <= A(1) XOR B(5);
		Carry(5) <= A(1) AND B(5);
		
		Sum(2) <= A(2) XOR B(6);
		Carry(6) <= A(2) AND B(6);
		
		Sum(3) <= A(3) XOR B(7);
		Carry(7) <= A(3) AND B(7);
		
		led(3 downto 0) <= Sum(3 downto 0);
		led(7 downto 4) <= Carry(7 downto 4);
		
	end half_adder;
