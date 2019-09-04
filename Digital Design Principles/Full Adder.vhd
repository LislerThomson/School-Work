library ieee;
use ieee.std_logic_1164.all;

entity ltplab6_2 is
port(sw : in std_logic_vector(8 downto 0);
led : out std_logic_vector(4 downto 0)
);
end ltplab6_2;

architecture Full_Adder of ltplab6_2 is
signal A :std_logic_vector(3 downto 0);
signal B :std_logic_vector(7 downto 4);
signal Cin:std_logic;
signal sum:std_logic_vector(3 downto 0);
signal cout:std_logic_vector(3 downto 0);

begin

A(3 downto 0) <= sw(3 downto 0);
B(7 downto 4) <= sw(7 downto 4);
Cin <= sw(8);
led (3 downto 0) <= sum;
led(4) <= cout(3);                                                                    

sum(0) <= A(0) XOR B(4) XOR Cin;
cout(0) <= (A(0) AND B(4))OR ((A(0) XOR B(4)) AND Cin);

sum(1) <=  A(1) XOR B(5) XOR cout(0);   
cout(1) <= (A(1) AND B(5)) OR (cout(0) AND (A(1) XOR B(5)));

sum(2) <=  A(2) XOR B(6) XOR cout(1);
cout(2) <= (A(2) AND B(6)) OR (cout(1) AND (A(2) XOR B(6)));


sum(3)<=A(3) XOR B(7) XOR cout(2);
cout(3)<=(A(3) AND B(7)) OR (cout(2) AND (A(3) XOR B(7)));

end Full_Adder;
