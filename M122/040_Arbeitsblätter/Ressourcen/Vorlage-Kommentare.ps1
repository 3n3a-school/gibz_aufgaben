<#
.SYNOPSIS  
    A summary of what this script does  
    Appears in all basic, -detailed, -full, -examples  
.DESCRIPTION  
    A more in depth description of the script  
    Should give script developer more things to talk about       
    Becomes: "DETAILED DESCRIPTION"  
    Appears in basic, -full and -detailed  
.NOTES  
    Additional Notes, eg  
    File Name  : Get-AutoHelp.ps1  
    Author     : Thomas Lee - tfl@psp.co.uk  
    Appears in -full   
.LINK  
    A hyper link, eg  
    http://www.pshscripts.blogspot.com  
    Becomes: "RELATED LINKS"   
    Appears in basic and -Full  
.EXAMPLE  
    The first example - just text documentation  
    You should provide a way of calling the script, plus expected output  
    Appears in -detailed and -full  
.COMPONENT  
   Not sure how to specify or use  
   Does not appear in basic, -full, or -detailed  
   Should appear in -component  
.ROLE   
   Not sure How to specify or use  
   Does not appear in basic, -full, or -detailed  
   Should appear with -role  
.FUNCTIONALITY  
   Not sure How to specify or use  
   Does not appear in basic, -full, or -detailed  
   Should appear with -functionality  
.PARAMETER foo  
   The .Parameter area in the script is used to derive the contents of the PARAMETERS in Get-Help output which   
   documents the parameters in the param block. The section takes a value (in this case foo,  
   the name of the first actual parameter), and only appears if there is parameter of that name in the  
   params block. Having a section for a parameter that does not exist generate no extra output of this section  
   Appears in -det, -full (with more info than in -det) and -Parameter (need to specify the parameter name)  
.PARAMETER bar  
   Example of a parameter definition for a parameter that does not exist.  
   Does not appear at all.  
#>

###############################################################################
# Programm: Encrypt.ps1
# Version 1.0 / 04.11.2015
# Roger Müller GIBZ
###############################################################################