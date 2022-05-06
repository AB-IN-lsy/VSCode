from Vertex import Vertex

import unittest


def assert_equal(got, expected, msg):
    """
    Simple assert helper
    """
    assert expected == got, \
        "[{}] Expected: {}, got: {}".format(msg, expected, got)


def assert_edges(got: 'list[Vertex]', expected: 'list[Vertex]'):
    """
    Assert helper to ensure returned edges are correct
    """
    assert_equal(len(got), len(expected), "Incorrect edges for vertex")
    for i in range(len(got)):
        assert got[i] in expected,\
            "Edge {} not in expected edges".format(got[i])


class SampleVertexTestCases(unittest.TestCase):
    """
    Sample testing functionality for the Vertex class
    Feel free to add your own tests here!
    """

    def setUp(self):
        """
        Set up the vertices to be used throughout the test
        This is a basic graph
        A(T)-B(U)
        |     |
        C(U)-D(T)
        """

        self.A = Vertex(True)
        self.B = Vertex(False)
        self.C = Vertex(False)
        self.D = Vertex(True)

        self.A.add_edge(self.B)
        self.A.add_edge(self.C)
        self.B.add_edge(self.D)
        self.C.add_edge(self.D)

    def test_vertex_construction(self):
        """
        Test that the sample graph is correctly constructed
        """
        assert_edges(self.A.get_edges(), [self.B, self.C])
        assert_edges(self.B.get_edges(), [self.A, self.D])
        assert_edges(self.C.get_edges(), [self.A, self.D])
        assert_edges(self.D.get_edges(), [self.B, self.C])

    def test_vertex_trusted_status(self):
        """
        Test that the sample graph has nodes with correct trusted status
        """
        assert_equal(self.A.get_is_trusted(), True, "A is trusted")
        assert_equal(self.B.get_is_trusted(), False, "B is not trusted")
        assert_equal(self.C.get_is_trusted(), False, "C is not trusted")
        assert_equal(self.D.get_is_trusted(), True, "D is trusted")

    def test_vertex_add_edge(self):
        """
        Test that an extra edge can be added to the sample graph
        """
        self.A.add_edge(self.D)

        assert_edges(self.A.get_edges(), [self.B, self.C, self.D])
        assert_edges(self.B.get_edges(), [self.A, self.D])
        assert_edges(self.C.get_edges(), [self.A, self.D])
        assert_edges(self.D.get_edges(), [self.A, self.B, self.C])

    def test_vertex_remove_edge(self):
        """
        Test that an edge can be removed from the sample graph
        """
        self.A.remove_edge(self.C)

        assert_edges(self.A.get_edges(), [self.B])
        assert_edges(self.B.get_edges(), [self.A, self.D])
        assert_edges(self.C.get_edges(), [self.D])
        assert_edges(self.D.get_edges(), [self.B, self.C])

    def test_vertex_update_status(self):
        """
        Test that the trusted status can be correctly updated
        """
        self.B.update_status(True)
        self.C.update_status(True)

        assert_equal(self.A.get_is_trusted(), True, "A is trusted")
        assert_equal(self.B.get_is_trusted(), True, "B is trusted")
        assert_equal(self.C.get_is_trusted(), True, "C is trusted")
        assert_equal(self.D.get_is_trusted(), True, "D is trusted")
