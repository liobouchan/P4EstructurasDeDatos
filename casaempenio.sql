-- MySQL Administrator dump 1.4
--
-- ------------------------------------------------------
-- Server version	5.6.11


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


--
-- Create schema casaempenio
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ casaempenio;
USE casaempenio;

--
-- Table structure for table `casaempenio`.`bienes`
--

DROP TABLE IF EXISTS `bienes`;
CREATE TABLE `bienes` (
  `idbienes` int(10) unsigned zerofill NOT NULL AUTO_INCREMENT,
  `nombreBien` varchar(100) NOT NULL DEFAULT '',
  `nombreCliente` varchar(100) NOT NULL DEFAULT '',
  `monto` int(10) unsigned NOT NULL DEFAULT '0',
  `fecha_inicio` varchar(45) NOT NULL DEFAULT '',
  `fecha_final` varchar(45) NOT NULL DEFAULT '',
  PRIMARY KEY (`idbienes`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `casaempenio`.`bienes`
--

/*!40000 ALTER TABLE `bienes` DISABLE KEYS */;
/*!40000 ALTER TABLE `bienes` ENABLE KEYS */;


--
-- Table structure for table `casaempenio`.`clientes`
--

DROP TABLE IF EXISTS `clientes`;
CREATE TABLE `clientes` (
  `idclientes` int(10) unsigned zerofill NOT NULL AUTO_INCREMENT,
  `nombre` varchar(100) NOT NULL DEFAULT '',
  PRIMARY KEY (`idclientes`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `casaempenio`.`clientes`
--

/*!40000 ALTER TABLE `clientes` DISABLE KEYS */;
/*!40000 ALTER TABLE `clientes` ENABLE KEYS */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
