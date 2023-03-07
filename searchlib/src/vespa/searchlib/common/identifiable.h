// Copyright Yahoo. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
#pragma once

#include <vespa/vespalib/objects/identifiable.h>

#define CID_AttributeVector                        SEARCHLIB_CID(1)
#define CID_NumericAttribute                       SEARCHLIB_CID(2)
#define CID_IntegerAttribute                       SEARCHLIB_CID(3)
#define CID_FloatingPointAttribute                 SEARCHLIB_CID(4)
#define CID_StringAttribute                        SEARCHLIB_CID(5)
#define CID_Int8Attribute                          SEARCHLIB_CID(6)
#define CID_Int16Attribute                         SEARCHLIB_CID(7)
#define CID_Int32Attribute                         SEARCHLIB_CID(8)
#define CID_Int64Attribute                         SEARCHLIB_CID(9)
#define CID_UInt8Attribute                         SEARCHLIB_CID(10)
#define CID_UInt16Attribute                        SEARCHLIB_CID(11)
#define CID_UInt32Attribute                        SEARCHLIB_CID(12)
#define CID_UInt64Attribute                        SEARCHLIB_CID(13)
#define CID_FloatAttribute                         SEARCHLIB_CID(14)
#define CID_DoubleAttribute                        SEARCHLIB_CID(15)
#define CID_AttributeVectorBase                    SEARCHLIB_CID(16)

#define CID_Aggregator                             SEARCHLIB_CID(20)
#define CID_MultiScalarIntegerAggregator           SEARCHLIB_CID(21)
#define CID_MultiScalarFloatingPointAggregator     SEARCHLIB_CID(22)
#define CID_BucketAggregator                       SEARCHLIB_CID(23)
#define CID_UniqueAggregator                       SEARCHLIB_CID(24)
#define CID_FixedWidthAggregator                   SEARCHLIB_CID(25)

#define CID_BucketList                             SEARCHLIB_CID(30)
#define CID_EnumBucketList                         SEARCHLIB_CID(31)
#define CID_IntBucketList                          SEARCHLIB_CID(32)
#define CID_FloatBucketList                        SEARCHLIB_CID(33)
#define CID_StringBucketList                       SEARCHLIB_CID(34)

#define CID_search_expression_ExpressionNode       SEARCHLIB_CID(40)
#define CID_search_expression_ResultNode           SEARCHLIB_CID(41)
#define CID_search_expression_FunctionNode         SEARCHLIB_CID(42)
#define CID_search_expression_UnaryFunctionNode    SEARCHLIB_CID(43)
#define CID_search_expression_BinaryFunctionNode   SEARCHLIB_CID(44)
#define CID_search_expression_MultiArgFunctionNode SEARCHLIB_CID(45)
#define CID_search_expression_UnaryBitFunctionNode SEARCHLIB_CID(46)
#define CID_search_expression_BitFunctionNode      SEARCHLIB_CID(47)
#define CID_search_expression_DocumentAccessorNode SEARCHLIB_CID(48)
#define CID_search_expression_ConstantNode         SEARCHLIB_CID(49)

#define CID_search_expression_NumericResultNode    SEARCHLIB_CID(50)
#define CID_search_expression_IntegerResultNode    SEARCHLIB_CID(51)
#define CID_search_expression_FloatResultNode      SEARCHLIB_CID(52)
#define CID_search_expression_StringResultNode     SEARCHLIB_CID(53)
#define CID_search_expression_RawResultNode        SEARCHLIB_CID(54)
#define CID_search_expression_AttributeNode        SEARCHLIB_CID(55)
#define CID_search_expression_DocumentFieldNode    SEARCHLIB_CID(56)
#define CID_search_expression_NullResultNode       SEARCHLIB_CID(57)
#define CID_search_expression_FieldValue2ResultNode \
                                                   SEARCHLIB_CID(58)
#define CID_search_expression_RelevanceNode        SEARCHLIB_CID(59)
#define CID_search_expression_InterpolatedLookup   SEARCHLIB_CID(39)
#define CID_search_expression_ArrayAtLookup        SEARCHLIB_CID(38)
#define CID_search_expression_ArrayOperationNode   SEARCHLIB_CID(37)

#define CID_search_expression_NegateFunctionNode   SEARCHLIB_CID(60)
#define CID_search_expression_AddFunctionNode      SEARCHLIB_CID(61)
#define CID_search_expression_MultiplyFunctionNode SEARCHLIB_CID(62)
#define CID_search_expression_DivideFunctionNode   SEARCHLIB_CID(63)
#define CID_search_expression_ModuloFunctionNode   SEARCHLIB_CID(64)
#define CID_search_expression_MinFunctionNode      SEARCHLIB_CID(65)
#define CID_search_expression_MaxFunctionNode      SEARCHLIB_CID(66)
#define CID_search_expression_AndFunctionNode      SEARCHLIB_CID(67)
#define CID_search_expression_OrFunctionNode       SEARCHLIB_CID(68)
#define CID_search_expression_XorFunctionNode      SEARCHLIB_CID(69)
#define CID_search_expression_MD5BitFunctionNode   SEARCHLIB_CID(70)
#define CID_search_expression_XorBitFunctionNode   SEARCHLIB_CID(71)
#define CID_search_expression_CatFunctionNode      SEARCHLIB_CID(72)
#define CID_search_expression_GetDocIdNamespaceSpecificFunctionNode  SEARCHLIB_CID(73)
#define CID_search_expression_GetYMUMChecksumFunctionNode            SEARCHLIB_CID(74)
#define CID_search_expression_TimeStampFunctionNode                  SEARCHLIB_CID(75)
#define CID_search_expression_RangeBucketPreDefFunctionNode          SEARCHLIB_CID(76)
#define CID_search_expression_FixedWidthBucketFunctionNode           SEARCHLIB_CID(77)
#define CID_search_expression_NumericFunctionNode                    SEARCHLIB_CID(78)
#define CID_search_expression_ExpressionTree                         SEARCHLIB_CID(79)

#define CID_search_aggregation_AggregationResult          SEARCHLIB_CID(80)
#define CID_search_aggregation_CountAggregationResult     SEARCHLIB_CID(81)
#define CID_search_aggregation_SumAggregationResult       SEARCHLIB_CID(82)
#define CID_search_aggregation_MaxAggregationResult       SEARCHLIB_CID(83)
#define CID_search_aggregation_MinAggregationResult       SEARCHLIB_CID(84)
#define CID_search_aggregation_AverageAggregationResult   SEARCHLIB_CID(85)
#define CID_search_aggregation_XorAggregationResult       SEARCHLIB_CID(86)
#define CID_search_aggregation_HitsAggregationResult      SEARCHLIB_CID(87)
#define CID_search_aggregation_ExpressionCountAggregationResult \
                                                          SEARCHLIB_CID(88)
#define CID_search_aggregation_StandardDeviationAggregationResult \
                                                          SEARCHLIB_CID(89)

#define CID_search_aggregation_Group                      SEARCHLIB_CID(90)
#define CID_search_aggregation_Grouping                   SEARCHLIB_CID(91)
#define CID_search_aggregation_GroupingLevel              SEARCHLIB_CID(93)
#define CID_search_aggregation_Hit                        SEARCHLIB_CID(94)
#define CID_search_aggregation_FS4Hit                     SEARCHLIB_CID(95)
#define CID_search_aggregation_VdsHit                     SEARCHLIB_CID(96)
#define CID_search_aggregation_HitList                    SEARCHLIB_CID(97)

#define CID_search_expression_BucketResultNode              SEARCHLIB_CID(100)
#define CID_search_expression_IntegerBucketResultNode       SEARCHLIB_CID(101)
#define CID_search_expression_FloatBucketResultNode         SEARCHLIB_CID(102)
#define CID_search_expression_StringBucketResultNode        SEARCHLIB_CID(103)
#define CID_search_expression_Int8ResultNode                SEARCHLIB_CID(104)
#define CID_search_expression_Int16ResultNode               SEARCHLIB_CID(105)
#define CID_search_expression_Int32ResultNode               SEARCHLIB_CID(106)
#define CID_search_expression_Int64ResultNode               SEARCHLIB_CID(107)

#define CID_search_expression_ResultNodeVector              SEARCHLIB_CID(108)
#define CID_search_expression_IntegerResultNodeVector       SEARCHLIB_CID(109)
#define CID_search_expression_FloatResultNodeVector         SEARCHLIB_CID(110)
#define CID_search_expression_StringResultNodeVector        SEARCHLIB_CID(111)
#define CID_search_expression_IntegerBucketResultNodeVector SEARCHLIB_CID(112)
#define CID_search_expression_FloatBucketResultNodeVector   SEARCHLIB_CID(113)
#define CID_search_expression_StringBucketResultNodeVector  SEARCHLIB_CID(114)
#define CID_search_expression_RawResultNodeVector           SEARCHLIB_CID(115)
#define CID_search_expression_Int8ResultNodeVector          SEARCHLIB_CID(116)
#define CID_search_expression_Int16ResultNodeVector         SEARCHLIB_CID(117)
#define CID_search_expression_Int32ResultNodeVector         SEARCHLIB_CID(118)
#define CID_search_expression_Int64ResultNodeVector         SEARCHLIB_CID(119)
#define CID_search_expression_DefaultValue                  SEARCHLIB_CID(120)
#define CID_search_expression_SingleResultNode              SEARCHLIB_CID(121)
#define CID_search_expression_EnumResultNode                SEARCHLIB_CID(122)
#define CID_search_expression_EnumResultNodeVector          SEARCHLIB_CID(123)
#define CID_search_expression_PositiveInfinityResultNode    SEARCHLIB_CID(124)
#define CID_search_expression_RawBucketResultNode           SEARCHLIB_CID(125)
#define CID_search_expression_RawBucketResultNodeVector     SEARCHLIB_CID(126)
#define CID_search_expression_AttributeResult               SEARCHLIB_CID(127)
#define CID_search_expression_GeneralResultNodeVector       SEARCHLIB_CID(128)
#define CID_search_expression_EnumAttributeResult           SEARCHLIB_CID(129)

#define CID_search_expression_StrLenFunctionNode            SEARCHLIB_CID(130)
#define CID_search_expression_ToStringFunctionNode          SEARCHLIB_CID(131)
#define CID_search_expression_NumElemFunctionNode           SEARCHLIB_CID(132)
#define CID_search_expression_StrCatFunctionNode            SEARCHLIB_CID(133)
#define CID_search_expression_ToFloatFunctionNode           SEARCHLIB_CID(134)
#define CID_search_expression_ToIntFunctionNode             SEARCHLIB_CID(135)
#define CID_search_expression_MathFunctionNode              SEARCHLIB_CID(136)
#define CID_search_expression_SortFunctionNode              SEARCHLIB_CID(137)
#define CID_search_expression_ReverseFunctionNode           SEARCHLIB_CID(138)
#define CID_search_expression_ZCurveFunctionNode            SEARCHLIB_CID(139)
#define CID_search_expression_UcaFunctionNode               SEARCHLIB_CID(140)
#define CID_search_expression_ToRawFunctionNode             SEARCHLIB_CID(141)
#define CID_search_expression_AggregationRefNode            SEARCHLIB_CID(142)
#define CID_search_expression_NormalizeSubjectFunctionNode  SEARCHLIB_CID(143)
#define CID_search_expression_DebugWaitFunctionNode         SEARCHLIB_CID(144)
#define CID_search_expression_AttributeMapLookupNode        SEARCHLIB_CID(145)
#define CID_search_expression_BoolResultNode                SEARCHLIB_CID(146)
#define CID_search_expression_BoolResultNodeVector          SEARCHLIB_CID(147)
#define CID_search_expression_RawAttributeResult            SEARCHLIB_CID(148)


#define CID_search_QueryNode                                SEARCHLIB_CID(150)
#define CID_search_Query                                    SEARCHLIB_CID(151)
#define CID_search_QueryTerm                                SEARCHLIB_CID(152)
#define CID_search_QueryConnector                           SEARCHLIB_CID(153)
#define CID_search_AndQueryNode                             SEARCHLIB_CID(154)
#define CID_search_AndNotQueryNode                          SEARCHLIB_CID(155)
#define CID_search_OrQueryNode                              SEARCHLIB_CID(156)
#define CID_search_EquivQueryNode                           SEARCHLIB_CID(157)
#define CID_search_PhraseQueryNode                          SEARCHLIB_CID(158)
#define CID_search_NotQueryNode                             SEARCHLIB_CID(159)
#define CID_search_NearQueryNode                            SEARCHLIB_CID(160)
#define CID_search_ONearQueryNode                           SEARCHLIB_CID(161)
#define CID_search_TrueNode                                 SEARCHLIB_CID(162)

#define CID_PredicateAttribute                              SEARCHLIB_CID(163)
#define CID_TensorAttribute                                 SEARCHLIB_CID(164)
#define CID_ReferenceAttribute                              SEARCHLIB_CID(165)

#define CID_search_NormalSketch                             SEARCHLIB_CID(170)
#define CID_search_SparseSketch                             SEARCHLIB_CID(171)
