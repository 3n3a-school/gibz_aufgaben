﻿Write-Host Maximum ($args | Measure-Object -Maximum).Maximum at Position $args.IndexOf([int] ($args | Measure-Object -Maximum).Maximum)