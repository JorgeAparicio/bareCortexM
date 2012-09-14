/*******************************************************************************
 *
 * Copyright (C) 2012 Jorge Aparicio <jorge.aparicio.r@gmail.com>
 *
 * This file is part of bareCortexM.
 *
 * bareCortexM is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * bareCortexM is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with bareCortexM. If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/

ABOUT
=====

bareCortexM is an Eclipse project template for bare metal development of ARM
Cortex M processors.

With this project you can compile, flash, run and debug code on various ARM
processors and microcontrollers. Currently there is complete support for the 
STM32F1XX, STM32F2XX and STM32F4XX microcontrollers.

DEPENDENCIES
============

This project uses extensively the following tools:

+ GNU Tools ARM Embedded
  (https://launchpad.net/gcc-arm-embedded)

+ Eclipse CDT
  (http://www.eclipse.org/)

+ GNU ARM plugin for Eclipse
  (http://sourceforge.net/projects/gnuarmeclipse/)

+ Zylin Embedded CDT plugin for Eclipse
  (http://opensource.zylin.com/embeddedcdt.html)

+ EmbSysRegView plugin for Eclipse (Not necessary, but recommended)
  (http://embsysregview.sourceforge.net/)

+ openOCD
  (http://openocd.sourceforge.net/)

INSTALLATION
============

Check the wiki for the installation steps.
(https://github.com/JorgeAparicio/bareCortexM/wiki)

CONFIGURATION
=============

You'll need to configure the project for your specific target, interface and
platform.

+ Choose your platform.
	- Go to Menu > Project > Properties.
	- C/C++ Build.
	- Click the Manage Configuration button next to the Configuration combo box.
	- Select your platform and click the Set Active button.

+ Select the correct linker script.
	- Go to Menu > Project > Properties.
	- C/C++ Build > Settings.
	- ARM Sourcery GCC C++ Linker > General.
	- Type in the Script file box: ../linker/<your target>.ld
	- The list of supported devices is in the linker folder.
	
+ Select the correct linker script.
	- Go to Menu > Project > Properties.
	- C/C++ Build > Settings.
	- ARM Sourcery GCC C++ Linker > General.
	- Type in the Script file box: ../linker/<your target>.ld
	- The list of supported devices is in the linker folder.
	
+ Configure the OpenOCD.
	- Go to Menu > Run > External Tools > External Tool Configurations.
	- Program > OpenOCD.
	- On the main tab:
	- Verify the OpenOCD location.
	- Modify the argument to match your interface and target:
	- -f openocd/interface/<interface>.cfg -f openocd/target/<target>.cfg
	- The list of supported interfaces is in the folder openocd > interface.
	- The list of supported targets is in the folder openocd > target.

+ Select the correct GDB script.
	- Go to Menu > Run > Debug Configurations.
	- Zylin Embedded debug (Native) > Flash and Debug.
	- On the Debugger tab.
	- Modify the GDB script:
	- gdb/<your target>.script
	- The list of supported targets is in the gdb folder.

LICENSE
=======

This project is licensed under the GNU General Public License (GPL) version 3.

See COPYING.GPL3.txt for more details. 