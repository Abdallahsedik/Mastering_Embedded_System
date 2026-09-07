ENTRY(reset)
MEMORY
{
    Mem (rwx) :0x00000000 , LENGTH = 64M 
}
SECTIONS
{
   .startup ;
   {
    startup.o(.text)
   }   
   
}