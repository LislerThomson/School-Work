library ieee;
use ieee.std_logic_1164.all;

entity ltplab9 is
port(RESET:in std_logic;
CLK:in std_logic;
LEDR:out std_logic_vector(7 downto 0)
);
end ltplab9;

architecture Counter of ltplab9 is
signal R:std_logic_vector(7 downto 4);
signal J:std_logic_vector(3 downto 0);

begin
	LEDR(7 downto 4) <= R(7 downto 4);
	LEDR(3 downto 0) <= J(3 downto 0);

	process (CLK)
	begin

		if RESET <= '0' then
			R<="1000";
			J<="0000";
		else if CLK <= '0' then
			R(4)<=R(5);
			R(5)<=R(6);
			R(6)<=R(7);
			R(7)<=R(4);
			J(0)<=J(1);
			J(1)<=J(2);
			J(2)<=J(3);
			J(3)<=NOT J(0);
		end if;
		end if;

	end process;

end Counter;
