test_that("the minimal example works", {
  r <- callr::r_session$new()
  r$run(function() {
    pkgload::load_all()
  })
  segment <- create_segment("hello")

  out1 <- r$run(function() {
    x <- runif(100)
    write_array("hello", "myobj", x)
    x
  })

  out2 <- read_array("hello", "myobj")

  expect_identical(out1, out2)
})
