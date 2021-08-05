-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Aug 05, 2021 at 04:20 AM
-- Server version: 10.4.19-MariaDB
-- PHP Version: 8.0.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `directions`
--

-- --------------------------------------------------------

--
-- Table structure for table `dir`
--

CREATE TABLE `dir` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `forward_dir` int(11) NOT NULL,
  `backward_dir` int(11) NOT NULL,
  `right_dir` int(11) NOT NULL,
  `left_dir` int(11) NOT NULL,
  `stop_dir` int(11) NOT NULL,
  `LIST` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `dir`
--

INSERT INTO `dir` (`ID`, `forward_dir`, `backward_dir`, `right_dir`, `left_dir`, `stop_dir`, `LIST`) VALUES
(0, 0, 0, 1, 0, 0, 33),
(0, 1, 0, 0, 0, 0, 34),
(0, 0, 0, 1, 0, 0, 35),
(0, 0, 0, 0, 0, 1, 36),
(0, 0, 0, 0, 1, 0, 37),
(0, 1, 0, 0, 0, 0, 38),
(0, 0, 1, 0, 0, 0, 39),
(0, 1, 0, 0, 0, 0, 40);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `dir`
--
ALTER TABLE `dir`
  ADD PRIMARY KEY (`LIST`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `dir`
--
ALTER TABLE `dir`
  MODIFY `LIST` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=41;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
